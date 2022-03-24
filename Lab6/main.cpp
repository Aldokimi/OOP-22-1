#include <iostream>
#include "infile.h"


using namespace std;

int main(){
    try{
        string filename;
        cout << "Enter a file name: ";
        cin >> filename;

        infile enumerator(filename);

        for(enumerator.first(); !enumerator.end(); enumerator.next())
            cout << enumerator.current() << endl;
    }catch(infile::Exceptions ex){
        cerr << "Filenot found!\n\n";
    }

    return 1;
}