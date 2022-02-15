#include <iostream>
#include "LTMatrix.h"

using namespace std;

int main()
{
    LTMatrix a;
    LTMatrix b;
    LTMatrix c(2);
    cout << "a:\n" << a << endl << endl;
    cout << "b:\n" << b << endl;
    cout << "a[2,3]= " << a.getElement(2,3) << endl;
    cout << "a[3,2]= " << a.getElement(3,2) << endl << endl;
    cout << "a+b:\n" << LTMatrix::add(a,b) << endl << endl;
    cout << "a*b:\n" << LTMatrix::multiply(a,b) << endl << endl;
    try {
        cout << "invalid sum:\n" << LTMatrix::add(c,a) << endl << endl;
    }
    catch (LTMatrix::DimensionMismatchException ex)
    {
        cout << "exception caught" << endl << endl;
    }
    try {
        cout << "invalid mul:\n" << LTMatrix::add(c,b) << endl << endl;
    }
    catch (LTMatrix::DimensionMismatchException ex)
    {
        cout << "exception caught" << endl << endl;
    }
    try {
        cout << "invalid vector length:\n";
        a.setVec({2,3,4,5});
    }
    catch (LTMatrix::InvalidVectorException ex)
    {
        cout << "exception caught" << endl << endl;
    }
    return 0;
}
