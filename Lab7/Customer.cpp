#include "Customer.h"

Customer::Customer(const std::string & filename){
    std::ifstream f(filename);
    f >> this->name;

    std::string s;
    while(f >> s){
        list.push_back(s);
    }
}

std::string Customer::purchase(const Store & store){
    std::stringstream s;
    for(std::string productName: this->list){
        Product* product;
        if(linearSearch(productName, store.foods, product)){
            cart.push_back(product);
            s << product->getName() << "  " << product->getPrice() << std::endl;
            store.foods->takeOutFromStock(product);
        }
    }

    for(std::string productName: this->list){
        Product* product;
        if(minSearch(productName, store.technical, product)){
            cart.push_back(product);
            s << product->getName() << "  " << product->getPrice() << std::endl;
            store.technical->takeOutFromStock(product);
        }
    }

    return s.str();
}

bool Customer::linearSearch(const std::string name,const Department* d, Product* &product) 
{
    bool l = false;
    for(Product* p : d->stock ) {
        // std::cout << "custmoer product name: " << name << " product name: " << p->getName() << std::endl;
        if ( l = (name == p->getName()) ) {
            product = p; 
            break;
        }
    }
    return l;
}

bool Customer::minSearch(const std::string name, const Department* d, Product* &product) 
{
    bool l = false;
    float min;
    for(Product* p : d->stock )  {
        if (p->getName() != name) continue;
        if (l) {
            if (min > p->getPrice()) {
                min = p->getPrice();
                product = p;
            }
        }
        else  {
            l = true;
            min = p->getPrice();
            product = p;
        }
    }
    return l;
}

