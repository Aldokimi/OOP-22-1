#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct Hackathon{
    std::string HackID;
    std::string name;

    std::vector<int> results;

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


void read(Hackathon& hack, Status & st, std::fstream &x){
    x >> hack;
    if(x.fail()) st = abnorm;
    else st = norm;
}

Hackathon maxBeforeFail(Hackathon & hack, Status & st, std::fstream & x){
    read(hack, st, x);
    Hackathon max = hack;
    while(st == norm && !hack.fail()){
        if(hack.avg() >= max.avg()){
            max = hack;
        }
        read(hack, st, x);
    }
    return max;
}


int main(){
    Hackathon hack;
    std::fstream x("./../input.txt");
    Status st = norm;
    Hackathon result = maxBeforeFail(hack, st, x);
    std::cout << "\n\n** grade 3: \n";
    std::cout << result << std::endl;

    return 1;
}
