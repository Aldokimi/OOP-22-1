#include <iostream>


class Product
{
private:
    std::string name;
    float price;
public:
    Product(std::string n, float i): name(n), price(i) {}


    // getters
    std::string getName(){
        return name;
    }

    float getPrice(){
        return price;
    }

};

