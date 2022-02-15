#include "LTMatrix.h"

LTMatrix::LTMatrix()
{
    m_size = 3;
    m_vec = {1,2,3,4,5,6};
    //1
    //2 3
    //3 4 5
}

LTMatrix::LTMatrix(const std::vector<int>& vec){
    setVec(vec);
}

LTMatrix::LTMatrix(int size){
    m_size = size;
    m_vec.resize((size * (size + 1)) / 2);
}

LTMatrix::LTMatrix(const std::string& filename){
    std::fstream f(filename);
    if (f.fail())
    {
        m_size=0;
        m_vec.clear();
    }
    else
    {
        int e;
        while (f >> e)
        {
            m_vec.push_back(e);
        }
        double n = calcSizeFromLength(m_vec.size());
        if (n==floor(n)) // 4.95 ~ 4 , 4.02 ~ 4
        {
            m_size=n;
        }
        else
        {
            m_size=0;
            m_vec.clear();
        }
    }
}

int LTMatrix::ind(int i, int j) const{
    return j + i *(i-1)/2 - 1;
}

double LTMatrix::calcSizeFromLength(unsigned int lenght){
    return (-1+sqrt(1+8 * lenght)) / 2;
    // -1 + sqrt(1 + 8 * 7) / 2
}

bool LTMatrix::inLowerTran(int i, int j) const{
    return (1<=j && j<=i && i<=m_size);
}

int LTMatrix::getElement(int i, int j) const{
    if (inLowerTran(i,j))
    {
        return m_vec[ind(i,j)];
    }
    else if (1<=j && j<=m_size && 1<=i && i<=m_size)
    {
        return 0;
    }
}

void LTMatrix::setVec(const std::vector<int>& vec){
    double n = calcSizeFromLength(vec.size()); /// calculate the matrix size based on the vector length
    if (n==floor(n)) ///if the supposed matrix size is integer
    {
        m_size = n;
        m_vec = vec;
    }
    else /// invalid vector length
    {
        throw InvalidVectorException();
    }
}

void LTMatrix::setElement(int i, int j, int e){
    if (1<=j && j<=i && i<=m_size) /// indices of the lower part
    {
        m_vec[ind(i,j)] = e; /// vector indexing starts at 0
    }
    else throw OutOfTriangleException();
}


LTMatrix LTMatrix::add(const LTMatrix& a, const LTMatrix& b){
    if (a.getSize() == b.getSize())
    {
        LTMatrix sum(a);
        for (int i=0;i<a.m_vec.size();i++)
        {
            sum.m_vec[i] += b.m_vec[i];
        }
        return sum;
    }
    else
    {
        throw DimensionMismatchException();
    }
}

LTMatrix LTMatrix::multiply(const LTMatrix& a, const LTMatrix& b){
    if (a.getSize() == b.getSize())
    {
        LTMatrix mul(a.getSize());
        for (int i=1;i<=a.m_size;i++)
        {
            for (int j=1;j<=a.m_size;j++)
            {
                if (a.inLowerTran(i,j)) /// only the lower triangular part need calculation
                {
                    for (int k=1;k<=a.m_size;k++)
                    {
                        mul.setElement(i,j,mul.getElement(i,j)+a.getElement(i,k)*b.getElement(k,j));
                    }
                }
            }
        }
        return mul;
    }
    else
    {
        throw DimensionMismatchException();
    }
}


std::ostream &operator<<(std::ostream &os,const LTMatrix& m)
{
    os << m.m_size <<"x"<<m.m_size<<std::endl;
    for (int i=1;i<=m.m_size;i++)
    {
        for (int j=1;j<=m.m_size;j++)
        {
            os << m.getElement(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}



//LTMatrix::LTMatrix() : m_size(3), m_vec({1,2,3,4,5,6}){}

//LTMatrix::~LTMatrix()
//{
//    //dtor
//}


