#include <iostream>
#include "./library/summation.hpp"
#include "./library/linsearch.hpp"
#include "./library/stringstreamenumerator.hpp"
#include "./library/seqinfileenumerator.hpp"



using namespace std;

struct Contest {
    string name;
    int rank;
    friend istream &operator >> (istream & is, Contest &c){
        is >> c.name >> c.rank;
        return is;
    }
};

struct sumResult {
    int bestRank;
    bool highJump;
    int noOfSilver;


    sumResult() {}
    sumResult(int br, bool hj, int nos) : bestRank(br), highJump(hj), noOfSilver(nos) {} 
};

class readContestants : public Summation<Contest, sumResult>{
    sumResult func(const Contest & e) const override {
        return sumResult(e.rank, e.name == "highjump", e.rank == 2 ? 1 : 0);
    }

    sumResult neutral () const override {
        return sumResult(98687, false, 0);
    }

    sumResult add(const sumResult& a, const sumResult& b) const override {
        return sumResult(a.bestRank < b.bestRank ? a.bestRank : b.bestRank, 
            a.highJump || b.highJump, a.noOfSilver + b.noOfSilver
        );
    }
};

struct Contestant {
    string name;
    string school;
    sumResult sr;

    friend istream &operator >> (istream & is, Contestant &c){
        string line;
        getline(is, line, '\n');

        stringstream ss(line);
        ss >> c.name >> c.school;
        StringStreamEnumerator<Contest> ssenor(ss);

        readContestants pr;
        pr.addEnumerator(&ssenor);
        pr.run();


        c.sr = pr.result();

        return is;
    }
};


class MySearch : public LinSearch<Contestant>{
    bool cond(const Contestant & e) const override{
        return (e.sr.bestRank == 2 && e.sr.highJump);
    }
};

int main (int argc, char** argv){

    try{
        string filename;
        if (argc > 1){
            filename = argv[1];
        }else{
            filename = "inp1.txt";
        }

        SeqInFileEnumerator<Contestant> enor(filename);
        MySearch pr;
        pr.addEnumerator(&enor);
        pr.run();

        if(pr.found()){
            cout << pr.elem().name << " from school name : " << pr.elem().school <<
            " with count of selvers : " << pr.elem().sr.noOfSilver ;
        }

    }catch(SeqInFileEnumerator<Contestant>::Exceptions err){
        cerr<<"File not fount \n";
        return 1;
    }

    return 0;
}
