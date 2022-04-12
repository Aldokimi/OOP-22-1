#include "Garden.h"

Garden::Garden(int n){
    if (n < 0) throw NUM_ERROR;

    this->parcels.resize(n);

    for(unsigned int i = 0; i < n; i++){
        this->parcels[i] = new Parcel();
    }
}

Parcel* Garden::getParcel(int i) const {
    if(i >=0 && i < parcels.size()) return parcels[i];
    else return nullptr;
}

void Garden::plant(int id, Plant* plant, int date){
    if(id < 1 || id > parcels.size()) throw PARCEL_ERROR;
    
    getParcel(id-1)->plant(plant, date);
}

std::vector<int> Garden::canHarvest(int date){
    std::vector<int> result;
    for (int i = 0; i < parcels.size(); i++)
    {
        Parcel* p = parcels[i];
        if( p->getPlant() != nullptr 
            && p->getPlant()->isVegetable()
            && date - p->getDate() == p->getPlant()->getRapeningTime()
        ){
            result.push_back(i+1);
        }
    }
    return result;
}