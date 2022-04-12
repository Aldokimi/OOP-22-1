#pragma once
#include "Garden.h"

class Gardener
{
private:
    Garden * garden;
public:
    Gardener(Garden* k) : garden(k){};
    Garden* getGarden(){return this->garden;};
    
};