#ifndef PRIORSOR_H_INCLUDED
#define PRIORSOR_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include <exception>

struct Item
{
    ///public attributes
    int key;
    std::string data;

    ///constructors
    Item(int key = 0, std::string data = "") : key(key), data(data) {}

    friend std::istream& operator>>(std::istream& is, Item& item){
        std::cout << "Key: ";
        is >> item.key ;
        std::cout<<"Data: ";
        is >> item.data;
        return is;
    }


    friend std::ostream& operator<<(std::ostream& os, const Item& item){
        os << "(" << item.key << "," << item.data << ")";
        return os;
    }

    
    bool operator==(const Item& b){ return (key == b.key && data == b.data); }

};

class Map
{
    public:
        class ExistingKeyException    : public std::exception {};
        class NonExistingKeyException : public std::exception {};

        // enum CustomExceptions { ExistingKeyException, NonExistingKeyException};

        int count() const { return mapVector.size();}
        void insert(Item a);
        void erase(int key) /*throw (std::exception)*/;
        bool isIn(int key) const;
        std::string &operator[](int key)  /*throw (std::exception)*/;
        bool isEmpty() const {return mapVector.size()==0;}
        // friend bool contain3( const Map & m);
        friend std::ostream& operator<<(std::ostream& s, const Map& m); ///print a line

        ///Methods for testing
        std::vector<Item> getItems() const;
        std::pair<bool,int> getLogSearch(int key) const {return logSearch(key);}

    private:
        std::vector<Item> mapVector; // we are going to store all the map content on this vector

        std::pair<bool,int> logSearch(int key) const;

};


#endif // PRIORSOR_H_INCLUDED
