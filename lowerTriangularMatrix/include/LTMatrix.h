/**
 * you can use #ifndef and #define and at the end of the file #endif
 * but you also can use '#pragma once' on the top only one time, and this is
 **/

//#ifndef LTMATRIX_H
//#define LTMATRIX_H

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <math.h>

class LTMatrix
{
    public:

        class InvalidIndexException : public std::exception{};
        class OutOfTriangleException : public std::exception{};
        class DimensionMismatchException : public std::exception{};
        class InvalidVectorException : public std::exception{};

        /**
         * Every class should have a constructor, so we can initialize our local variables and to do some operations
         * up on creating the class
         **/
        LTMatrix();
        LTMatrix(const std::vector<int>& vec);
        LTMatrix(int size);
        LTMatrix(const std::string& filename);
        //virtual ~LTMatrix();

    //protected:

        // getters
        int getSize() const {return m_size;}
        int getElement(int i, int j) const ;

        // setters
        void setVec(const std::vector<int>& vec);
        void setElement(int i, int j, int e);

        //
        static LTMatrix add(const LTMatrix& a, const LTMatrix& b);
        static LTMatrix multiply(const LTMatrix& a, const LTMatrix& b);

        // fstream => ostream , istream
        friend std::ostream &operator<<(std::ostream &os, const LTMatrix& m);
    private:
        /**
         * Here you declare all the private variables and functions, meaning that you cannot access those variables or functions
         * from outside the class scope!
         **/
        int m_size;
        std::vector<int> m_vec;

        int ind(int i, int j) const; /// to get the element from the matrix at the column i and the row j
        double calcSizeFromLength(unsigned int lenght); /// get the size of the matrix from the size of the vector
        bool inLowerTran(int i, int j) const; /// check if the element at the column i and the row j does exist

};

//#endif // LTMATRIX_H
