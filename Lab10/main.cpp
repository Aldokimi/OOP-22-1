#include <iostream>
#include "library/summation.hpp"
#include "library/enumerator.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/maxsearch.hpp"



using namespace std;

struct Mark {
    string name;
    int mark;
    friend istream& operator >> (istream &is, Mark &m);
};

istream& operator >> (istream &is, Mark &m){
    is >> m.name >> m.mark;
    return is;
};

struct Result{
    int sum;
    int count;

    Result(){}
    Result(int s, int c) : sum(s), count(c) {}
};

class Average : public Summation<Mark, Result>
{
private:
    string name;
public:
    Average (const string &name) : name(name){}
protected:
    Result func(const Mark& e) const override {
        return Result(e.mark, 1);
    }
    Result neutral() const override {return Result(0, 0);}
    Result add(const Result& a, const Result& b) const override {
        return Result(a.sum + b.sum , a.count + b.count);
    }

    bool whileCond(const Mark &e) const override{return e.name == this->name;}
    void first() override {}
};


struct Student{
    string name;
    double avr;
};


class StudentEnumerator : public Enumerator<Student>
{
private:
    SeqInFileEnumerator<Mark> * f;
    Student student;
    bool m_end;
public:
    StudentEnumerator(const string &fileName) {
        f = new SeqInFileEnumerator<Mark>(fileName);
    }
    ~StudentEnumerator(){delete f;}

    void first() override {f->first(); this->next();}
    void next() override;
    Student current() const override{return this->student;}
    bool end() const override{return this->m_end;}

};

void StudentEnumerator::next(){
    if(m_end = f->end()) return;
    this->student.name = f->current().name;

    Average pr(student.name);
    pr.addEnumerator(f);

    pr.run();

    if(pr.result().count > 0) student.avr = double(pr.result().sum) / pr.result().count;
    else student.avr = 0;
};



class BestStudent : public MaxSearch<Student, double>{
protected:
    double func(const Student & e) const override { return e.avr;}
};

int main(){

    try
    {
        BestStudent pr;
        StudentEnumerator myenor("input.txt");
        pr.addEnumerator(&myenor);

        pr.run();

        if(pr.found()){
            cout << pr.optElem().name << " is the best with average " << pr.opt();
        }else{
            cout << "File is empty!";
        }
    }
    catch(SeqInFileEnumerator<Mark>::Exceptions ex)
    {
        std::cerr << "File does not exists!" << '\n';
        return 1;
    }
    

    return 0;
};

