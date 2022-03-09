#include "map.h"

using namespace std;

/*
 * logarighmic search or binary search, this algorithm is used to find an item between a sorted sequence of items!
 * First we are choosing an upper bound and a lower bound, second we choose the middle point in the sequence,
 * then we check if the element in the middle point is greater, smaller, or equal to the element that we are looking for,
 * if it is greater, then our lower bound is going to be the next element after the middle element in the sequence, then
 * we are going to choose a new middle point based on the new lower bound and the upper bound, if the middle element is smaller,
 * then the upper bound is going to be the element before the middle point and we are going to do the same procces untill we find 
 * a middle point element which is equal to the element that we are lookig for!
 */
pair<bool,int> Map::logSearch(int key) const{

    bool exists = false;
    int lowerBound = 0; 
    int upperBound = mapVector.size()-1;
    int middlePoint;

    while (!exists && lowerBound <= upperBound){

        middlePoint = (lowerBound + upperBound) / 2;
        if (mapVector[middlePoint].key>key) { upperBound = middlePoint - 1; }
        else if (mapVector[middlePoint].key<key) { lowerBound = middlePoint + 1; }
        else { exists = true; }
    }

    // if an element doesn't exists then we return the possible position to add this elemet to!
    if (!exists) middlePoint = lowerBound;
    
    // the middlePoint will represent the index of the element that we are looking for!
    return pair<bool,int>(exists,middlePoint);
}

/* We need to insert an element in the right place, we need to keep the keys of the element sorted, so
 * we are doing a logSearch to check if the element exists or not, if it exists then we throw an exception because 
 * keys in a map cannot be repeated, but if the key doesn't exist then we insert this key in the right place (this right
 * place is givin by the logSearch), the method of inserting is that we create an additional place for the new element
 * then we shift all the elements up from the point where we want to add our new element, then we instert it at it's position 
 * since it is going to be free!
 */
void Map::insert(Item e){

    pair<bool,int> out = logSearch(e.key);

    if (!out.first){ // if an element doesn't exist in a map

        mapVector.resize(mapVector.size()+1);

        for (int i = mapVector.size() - 2; i >= out.second; i--) 
         mapVector[i+1] = mapVector[i];

        mapVector[out.second] = e;
    }
    else  throw ExistingKeyException();
    
}

/* Erasing an element is somehow similar to inserting an element, we just shift all the element back from the positin
 * of the element, then this element will be overriden with the element after it, and due to the shifting we will have 
 * an empty place at the end of the vector so we jut pop_back it!
 */

void Map::erase(int key) { /*throw (std::exception)*/

    std::pair<bool,int> out = logSearch(key);

    if (out.first) {

        for (unsigned int i=out.second+1;i<mapVector.size();i++)
         mapVector[i-1] = mapVector[i];
        
        mapVector.pop_back();
    }
    else  throw NonExistingKeyException();
    
}

bool Map::isIn(int key) const{

    return logSearch(key).first;
}

std::string &Map::operator[](int key) { /*throw (std::exception)*/

    pair<bool,int> out = logSearch(key);

    if (out.first) return mapVector[out.second].data;

    else throw NonExistingKeyException();
    
}

ostream& operator<<(std::ostream& s, const Map& m) {

    s << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    s << "Number of elements: " << m.mapVector.size() << "\nContent: " << endl;
    for(unsigned i = 0; i < m.mapVector.size(); ++i){
        s << " " << m.mapVector[i];
    }
    s << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
    return s;
}

std::vector<Item> Map::getItems() const {

    std::vector<Item> v;
    for(unsigned i=0; i<mapVector.size(); ++i) v.push_back(mapVector[i]);

    return v;
}

