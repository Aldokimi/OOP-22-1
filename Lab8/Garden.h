#pragma once
#include <vector>
#include "Parcel.h"

class Garden {
    private:
        std::vector<Parcel*> parcels;
    public:
        enum Error {PARCEL_ERROR, NUM_ERROR};
        Garden(int n);
        Parcel* getParcel(int i) const;
        void plant(int id, Plant* plant, int date);
        std::vector<int> canHarvest(int date);
};