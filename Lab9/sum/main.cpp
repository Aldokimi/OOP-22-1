#include <iostream>
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"

class MySum : public Summation<int>
{
protected:
    int func(const int& e) const override {return e;}
    int neutral() const override {return 0;}
    int add(const int& a, const int& b) const override {return a + b;}
};

int main(){
    try
    {
        MySum pr;
        SeqInFileEnumerator<int> enor("input.txt");
        pr.addEnumerator(&enor);
        pr.run();

        std::cout << "Sum = " << pr.result() << std::endl;
    }
    catch(SeqInFileEnumerator<int>::Exceptions ex)
    {
        std::cerr << "File error!" << '\n';
    }
    

}
