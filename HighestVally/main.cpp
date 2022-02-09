/*****************************************
*   Author: Mohammed Aldokimi            *
*   E-mail: eespb3@inf.elte.hu           *
*   Date: 2022. 02. 08.                  *
*   Project name: Highest valley         *
*****************************************/

/**
 * TASK:
 * 
 * Find the highest valley: ​
 * Given altitude measurements in a file. Find the highest valley 
 * (the highest measurement that is lower then the measurements before and after it).​
 **/


#include <iostream>
#include <vector> 
#include <fstream>

using namespace std;


/**
 * You always need to decleare your function on the top of the main function, or you can imiplement your function on this area!
 **/
bool fileSetup(vector<int> &vec, const string &filename);
bool condMaxSreatch(const vector<int> &x, int &maxi , int &ind);
bool condMaxSreatchFromAfile(const string &filename, int &maxi);

int main()
{
    // reading the file name from the console
    cout << "Enter a file name: " ;
    string filename; // to store the file name!
    cin >> filename;

    // the vector that will store the mesurements ( we will fill this vector in the fileSetup function and we will use the filled vector on the condMaxSreatch function )
    vector<int> vec;

    // maxi will be our highest valley, and ind is the position index of our highest valley!
    int maxi, ind;

    bool fileExists = fileSetup(vec, filename); // it will return true if the file exists!

    if(fileExists == true){

        bool maxSearchWorks = condMaxSreatch(vec, maxi, ind); // it will return true if we have a highest valley!

        if(maxSearchWorks){
            cout << "The maximum valley is: " << maxi << " and it is in index number: " << ind << endl;
        }else{
            cout << "No valley exists!" << endl;
        }

        if(condMaxSreatchFromAfile(filename, maxi)){
            cout << "The maximum search from a file result is: " << maxi << endl;
        }else{
            cout << "No valley exists!" << endl;
        }

    }else{
        cout << "File doesn't exitst";
    }

    return 0;
}

/**
 * This function is used to read the file and store the data into a vector!
 * here we are passing the vectore by refrence so we take the original vectore (not a copy of it) and we fill it or do any operations with it!
 * you might faced a problem when you want to return 2 values or 3 values from a function but the function can return only one object, so passing the 2 or three values
 * that you want to return by refrence will solve this problem for you (so you will pass the original values and they will be changed during the funciton life time).
 * 
 * Here you will notice that we are passing the file name by refrence while we don't need to modify it at all, so here we used the (const) keyword to say that this instance
 * of the file name will not be changed inside the function, we are using this approach to prevent any possible changes that could happen to the file name by mistake!  
 **/
bool fileSetup(vector<int> &vec, const string &filename){

    fstream fileStream(filename); // fstream represents the file stream data type, its used to create, write into and read from a file 

    if(fileStream.fail()){ // the fail() method will fail if the file doesn't exists on the path of the project (IE: next to the main) 
                          // NOTE: the file name here represents the path of the flie!
        return false;
    }
    int num;
    vec.clear(); // the clear() method deletes all the stored data from inside the vectore
                // (we are using it here just to make sure that we have an empty vector to store the measurements from the file)

    while(fileStream >> num){ /* the >> operator used to read an information from the file into a variable 
                                 (the information should be the same type like the variable), it reads one information at a time
                                 for instance if here we have the variable num, this variable is of type (int) so when we read from the file by using 
                                 the fileStream instance, so if our file contain '1 2 3' then (fileStream >> num) will work, return true, and store 1 into num
                                 because 1 is integer (same type like num) then when we call (fileStream >> num) for the second time it will read the second value 
                                 in the file which is '2', if we have any other type information inside the file (for example: 1 a 2 3) the a will be skiped and 
                                 the spaces as well ( NOTE: we need to have sperators between our information like spaces or new lines'/n' )!
                               */
        
        vec.push_back(num); // the push_back(V) function insertes an element to the begaining of our vertor!
    }
    //fileStream.close(); // the close() function is totally optional, since whe we are done with operations on the flie stream the distractor of the file steam will be called!
    return true;
}

/**
 * This is the implementation of the conditional maximum search as implemented on the specifcation!
 * The goal of this algorithm in this task is to get the greates valley from a sequence of measurements (numbers)!
 * A valley is a number with is smaller than the numbers before it and after it! (e.g.  7 6 8 here 6 is a valley because it is smaller than 7 and 8)
 **/

bool condMaxSreatch(const vector<int> &x, int &maxi , int &ind){

    bool l = false; // this logical value will decide if we have a valey or not!

    /* here we are going to iterate around the sequence of numbers or measurements that we have and at every element of this sequence we will check weather if its a
       vally or not!
    */
    /* here we start the loop from the second element on the sequence and we end it with element before the last one in the sequence, and the reason behind that is 
       for example if we have '1 2 3 4' as our input we don't need to consider '1' becuse there is not number before it and same with '4' because there is not number
       after it!
    */
    for(int i = 1; i < x.size() - 1; i++){ // the size() function returns the nubmer of elements stored on the vector!

        //if(!(x[i-1] >= x[i] && x[i] <= x[i+1])){} // this is a part of the algorithm diagram that we discussed on the class, its totally not needed!

        if(!l && (x[i-1] >= x[i] && x[i] <= x[i+1])){ 

            /* this condition is to find the first vally so we can initialize the (maxi) variable which will hold the 
                highest valley, also same with (l) to say that we have found a vally and (ind) to return the possition of the vally! 
                (the vally condition is (x[i-1] >= x[i] && x[i] <= x[i+1]) ) 
            */

            l    = true;
            maxi = x[i];
            ind  = i;
        }

        // we will enter this condition after we find the first valley (this condition also will edtermine if we have a valley or not)
        if(l && (x[i-1] >= x[i] && x[i] <= x[i+1]) ){ 
            
            if(maxi < x[i]){ // if the new valley is greater that the previous one then the new vally will the highest valley!
                maxi = x[i];
                ind = i;
            }

        }
    }

    return l;
}

/**
 * This function is kind of the composition of the two functions above 
 * (We are going to read the data from the file and get the highest valley directly without the need of a vector to store our data)
 **/

bool condMaxSreatchFromAfile(const string &filename, int &maxi){
    fstream filestream(filename);
    int before, current, after;

    // here we are reading the first 3 numbers from the file!
    filestream >> before;
    filestream >> current;
    filestream >> after;

    bool l = false;

    while(!filestream.fail()){ // here the fail will happen when we reach the end of the file (EOF) so while we can read from our file stream we loop!

        if(!l && current <= before && current <= after){
            l = true;
            maxi = current;
        }

        if(l && current <= before && current <= after){
            if(maxi < current){
                maxi = current;
            }
        }

        /* now we are moving around the file so for example if we are reading '1 2 3 4' we read the first three up in this function but now we are going to read  
           the fourth number to 'after' and shift the 'becfore' and 'current', then the fifth number and so on untill we reach (EOF) 
        */
        before = current;
        current = after;
        filestream >> after;
    }

    return l;
}
