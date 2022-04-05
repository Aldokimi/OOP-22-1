#include <iostream>
#include "Customer.h"

int main(){
    Customer c("input/customer1.txt");
    Store s("input/foods.txt", "input/technical.txt");

    std::cout << c.getName() << " has bought the following: \n" << c.purchase(s);

    return 1;
}