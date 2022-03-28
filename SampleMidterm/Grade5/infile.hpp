#pragma once

#include <ostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Hackathon{
    std::string HackID;
    std::string name;

    std::vector<int> results;

    int countMore80 = 0;

    friend std::ostream &operator<<(std::ostream &os, Hackathon &hack){

        os << "Hackathon ID: " << hack.HackID << ", name of competitor: " << hack.name << ", results: ";
        for(int x : hack.results) os << x << " ";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Hackathon &hack)
    {
        std::string line;
        std::getline(is , line ,'\n');
        std::stringstream ss(line);
        ss >> hack.HackID >> hack.name;
        int e;
        hack.results.clear();

        while(ss >> e ){
            hack.results.push_back(e);
        }

        return is;
    }

    float avg(){
        int sum = 0;
        for(int a : results){
            sum += a;
        }
        return sum/results.size();
    }

    bool fail(){
        return avg() < 40;
    }

};

enum Status{norm, abnorm};

class infile
{
public:
    enum Exception { OPEN_ERROR };

    infile(const std::string &fileName);
    ~infile();

    void first() { read(); next(); }
    void next();
    Hackathon current() const { return curr; }
    bool end() const { return m_end; }

private:
    std::ifstream x;
    Status st;
    Hackathon e;
    Hackathon curr;
    bool m_end;

    void read();
};

