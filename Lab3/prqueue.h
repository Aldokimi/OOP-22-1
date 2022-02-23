#ifndef PRIORSOR_H_INCLUDED
#define PRIORSOR_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>


/**
 * A class is just like a structure, so if you are creating a stuct it is just a way of storing
 * and orgnizing the data, however the class has more freedom and extra features!
 */
struct Item {
    // A single Item will contain those 2 fields, priority and data
    int priority;
    std::string data;

    ///constructors
    Item() // defaul constructor 
    {
        this->priority = 0;
        this->data = "";
    }; 

    Item(int pr,std::string da):priority(pr), data(da) {}

    friend std::ostream& operator<<(std::ostream& os, const Item& item) {

        os<<"( priority: " << item.priority << " data: " << item.data<< " )";
        return os;
    }
    //cout << item 

    friend std::istream& operator>>(std::istream& is, Item& item) {
        
        std::cout<<"Priority >>> ";
        is >> item.priority;
        std::cout<<"Data >>> ";
        is >> item.data;
        return is;
    }
    // cin >> Item
    ///for testing
    bool operator==(const Item& leftHandSideItem) { 
        return (priority == leftHandSideItem.priority && data == leftHandSideItem.data); 
    }
    // fst == sen
};

class PrQueue
{
    public:
    
        // error enumerator which will contain all the errors related to functionality of the class!
        enum PrQueueError { 
            EMPTY_PRQUEUE
        };

        ///PrQueue(); //Not needed
        ///~PrQueue() {} //Not needed

        void add(Item a) { items.push_back(a); }; // add a new item to our queue 
        Item removeMax() throw (PrQueueError); ///take out the item with the highest priority
        Item max() const throw (PrQueueError); ///get the item with the highest priority
        bool isEmpty() {return items.size() == 0;}

        ///Methods for testing
        friend std::ostream& operator<<(std::ostream& os, const PrQueue& pq); ///print a line
        unsigned int getLength() const {return items.size();}
        unsigned int getCapacity() const {return items.capacity();} // returns the size of the storage space currently allocated for the vector
        std::vector<Item> getItems() const;
        int getMaxindex() const {return maxindex();} ///maxindex is private, cannot be called outside

    private:
        std::vector<Item> items; /// sequence of items implemented as a vector
        int maxindex() const; /// index of the maximal element

};


#endif // PRIORSOR_H_INCLUDED
