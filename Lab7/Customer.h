#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "Store.h"

class Customer
{
private:
    std::string name;
    std::vector<std::string> list;
    std::vector<Product *> cart;

    bool linearSearch(const std::string name, const Department* d, Product* &product);
    bool minSearch(const std::string name,const Department* d, Product* &product);
    
public:
    Customer(const std::string & filename);
    std::string purchase(const Store &store);

    std::string getName(){
        return this->name;
    }
};
