#include <iostream>
#include <vector>
#include <fstream>
#include "Product.h"


class Department
{
public:

    std::vector<Product*> stock;
    Department(const std::string filename){
        std::ifstream f(filename);
        float price;
        std::string name;
         while(f >> name >> price){
             stock.push_back(new Product(name, price));
         }
    }

    void takeOutFromStock(Product * product){
        bool l = false;
        int ind;
        for(int i = 0; !l && i < stock.size(); i++){
            l = stock[i] == product;
            ind = i;
        }
        if(l) stock.erase(stock.begin() + ind);
    }
};
