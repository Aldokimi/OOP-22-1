/** Calculate the average of daily temperatures stored in a sequential input file.
a.) before the first temperature under the freezing point.
b.) after the first temperature under the freezing point.
c.) before and after the first temperature under the freezing point where in the after version the first freezing temperature is included, too.
*/

#include <iostream>
#include <fstream>

using namespace std;
enum Status {norm, abnorm};


/*
 * This function is responsable of reading one element from a sequential input file, and also to check the status of our program
 */
void read(Status & st, double & e, fstream &x){
    x >> e; // reading one elment 
    if(x.fail()) st = abnorm; // if the file reading fail then the status of our program is abnorm
    else st = norm;
}


/**
 * TASK 1: Solution: we need to get the average of the temperatures BEFORE the first temperature under the freezing point,
 * so we first read an element, then we check if this element is not under 0 (0 is the freezing point) and if the reading didn't fail,
 * then we loop untill we find the first number under 0, while looping we keep suming the numbers into the variable s and we also keep increasing the counter c,
 * at the end we will divide the sum withe count fo the elements to get the average!
 * @param x 
 * @return double 
 */
double before(fstream & x){
    double s = 0;
    int c = 0;
    Status st;
    double e;
    read(st, e, x); // we need to have at least 1 number in the file, if the while fails because of the end of the file then we will not find result
    while(st == norm && e >= 0){
        s += e;
        ++c;
        read(st, e, x);
    }
    // if(c != 0) return s / c;
    // else return 0;
    return (c != 0) ? s / c : 0;
}

/**
 * TASK 2: Solution: we need to get the average of the temperatures AFTER the first temperature under the freezing point,
 * so we first read an element, then we check if this element is not under 0 (0 is the freezing point) and if the reading didn't fail,
 * if so then we keep looping and reading the elements from the file untill we find the firt number under the freezing point, after we find this number we read it 
 * then we loop and we keep suming the numbers into the variable s and we also keep increasing the counter c,
 * at the end we will divide the sum withe count fo the elements to get the average!
 * @param x 
 * @return double 
 */
double after(fstream & x){
   
    Status st;
    double e;
    read(st, e, x); // we need to have at least 2 numbers in the file, if the while fails because of the end of the file then we will not find result
    while(e >= 0 && st == norm){
            read(st, e, x);
    }
    double s = 0;
    int c = 0; 
    read(st, e, x); // we don't need to count the number under the freazing poing on our average, so we read the next number
        

    while(st == norm){
        s += e;
        ++c;
        read(st, e, x);
    }
    return (c != 0) ? s / c : 0;
}

/**
 * TASK 3: Here we are basically applying the first and the second Tasks solution to get the temperatures BEFORE AND AFTER the freezing point (keep in mind that we also don't 
 * want to have the freezing poing on our average for all the tasks we have!)
 * 
 * @param x 
 * @return pair<double, double> 
 */

pair<double, double> beforeAfter(fstream & x){

    pair<double, double> result;
    double s1 = 0;
    int c1    = 0;

    Status st;
    double e;

    read(st, e, x);
    while(st == norm && e >= 0){
        s1 += e;
        ++c1;
        read(st, e, x);
    }
    result.first = (c1 != 0) ? s1 / c1 : 0;

    double s2;
    double c2;
    read(st, e, x);
    while(st == norm){
        s2 += e;
        ++c2;
        read(st, e, x);
    }
    result.second = (c2 != 0) ? s2 / c2 : 0;

    return result;
}

/**
 * Another answer is to use the functions that we have already, we just need to take the file pointer one step back after we finish getting 
 * the average before the freezing point, so that we have now a number which is under the freezing point and then we will read all the numbers 
 * after it by the second function!
 * 
 * @param x 
 * @return pair<double, double> 
 */
// pair<double, double> beforeAfter(fstream & x){
//     pair<double, double> result;
//     result.first = before(x);
//     x.seekg(-8, ios::cur); // the seekg will set the file pointer to any place you want (you need to specify the distance by bytes and from where to go)
//                           // so basically we are saying here that we want to move from the current position (ios::cur) back by one double number (-8 bytes)
//     result.second = after(x);
//     return result;
// }


/**
 * @brief Get the Stream object
 * 
 * We are passing a file name and then we return a pointer of a file stream!
 * 
 * @param fileName 
 * @return fstream* 
 */
fstream* getStream(const string &fileName){
    fstream* f = new fstream(fileName);
    return f;
}


int main(){

    fstream f;

    /**
     * we are passing *getStream("input.txt") so we can get a refrence .
     *  you convert pointer to refrence by adding * to the poiner, e.g: 
     *          int* p; // p now is a pointer
     *          p = *p; // p now is a refrence
     */
    cout << before(*getStream("input.txt")) << endl;
    cout << after(*getStream("input.txt")) << endl;
    pair<double, double> result = beforeAfter(*getStream("input.txt"));
    cout << result.first << " " << result.second << endl;

    return 0;
}