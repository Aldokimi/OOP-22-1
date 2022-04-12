#pragma once
#include "Plant.h"

class Parcel{
    private:
        Plant* m_plant;
        int plantingDate;
    public:
        enum Error {PLANTING_ERROR};
        Parcel() : m_plant(nullptr), plantingDate(1) {};
        void plant(Plant* p, int date){
            if(date < 1 || date > 12) throw PLANTING_ERROR;
            this->m_plant = p;
            this->plantingDate = date;
        }
        Plant* getPlant(){return this->m_plant;}
        int getDate(){return this->plantingDate;}
};