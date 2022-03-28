#include <iostream>
#include "infile.hpp"


int main()
{
    std::cout << "\n\n** grade 5: \n";
    
    try
    {
        infile t("./../input.txt");
        t.first();
        int max = t.current().countMore80;
        std::string maxComp = t.current().name;
        std::string hackName= t.current().HackID;
        for (; !t.end(); t.next())
        {
            if(t.current().countMore80 > max){
                max = t.current().countMore80;
                maxComp = t.current().name;
                hackName= t.current().HackID;
            }
        }
        if(max != 0) std::cout << "\nThe competitor is: " << maxComp <<" at the " + hackName + " !" << std::endl;
        else std::cout << "There is no competitor who scored more than 80%! \n";
    }
    catch (infile::Exception e)
    {
        std::cerr << "Opening file failed.\n";
        exit(-1);
    }

    return 0;
}