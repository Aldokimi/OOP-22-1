#include <iostream>
#include "Gardener.h"

int main(){
    Garden* garden = new Garden(5);
    Gardener* gardener = new Gardener(garden);

    gardener->getGarden()->plant(1, Potatoe::instance(), 3);
    gardener->getGarden()->plant(2, Pea::instance(), 3);
    gardener->getGarden()->plant(4, Pea::instance(), 3);
    gardener->getGarden()->plant(5, Rose::instance(), 3);

    for(int i : gardener->getGarden()->canHarvest(6)){
        std::cout << i << std::endl; 
    }

    return -1;
}