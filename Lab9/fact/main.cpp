#include <iostream>
#include "../library/summation.hpp"
#include "../library/intervalenumerator.hpp"


class Factorial : public Summation<int>
{
    protected:
    int func(const int& e) const override {return e;}
    int neutral() const override {return 1;}
    int add(const int& a, const int& b) const override {return a * b;}
};


int main(){

    int n;
    do{
        std::cout << "Enter an integer number: " ;
        std:: cin >> n;
    }while (n < 0);

    Factorial pr;
    IntervalEnumerator enor(2, n); // 2 .. 8
    pr.addEnumerator(&enor);
    pr.run();
    
    std::cout << "Factorial of the number "<< pr.result() << std::endl;
    return 1;
}