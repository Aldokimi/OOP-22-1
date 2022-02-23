#include "prqueue.h"

using namespace std;

Item PrQueue::removeMax() throw (PrQueueError) {

    if(items.size() == 0) throw EMPTY_PRQUEUE;
    int ind = maxindex();

    Item newItem = items[ind];
    items[ind] = items[items.size()-1]; ///Last item is put to the place of the taken element
    
    items.pop_back();
    
    return newItem;
}

Item PrQueue::max() const throw (PrQueueError) {

    if( items.size() == 0 ) throw EMPTY_PRQUEUE;
    int ind = maxindex();
    return Item(items[ind]);
}

ostream& operator<<(std::ostream& os, const PrQueue& pq) {

    os<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    os<<"Number of elements: " << pq.items.size() << "\nContent: " << endl;

    for(Item item : pq.items){
        os << " (" << item.priority << ", " << item.data << ")";
    }

    os << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
    return os;
}

int PrQueue::maxindex() const {

    int ind = 0;
    for(unsigned i=1; i < items.size(); ++i)
        if(items[i].priority>items[ind].priority) ind = i ;
        
    return ind;
}

vector<Item> PrQueue::getItems() const {

    vector<Item> v;
    for(unsigned i=0; i<items.size(); ++i)
        v.push_back(items[i]);
    return v;
}
