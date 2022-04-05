#include <iostream>
#include "Department.h"
class Store
{
public:
    Store(const std::string &  foodsFile, const std::string &  techFile){
        foods = new Department(foodsFile);  
        technical = new Department(techFile);    
    }

    Department* foods;
    Department* technical;

};
