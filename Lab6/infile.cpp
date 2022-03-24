#include "infile.h"


infile::infile(const std::string &filename)
{
    m_x.open(filename);
    if(m_x.fail()) throw OPEN_FILE_ERROR;
}

void infile::read(Status & sx, int & dx, std::fstream &x){
    x >> dx; // reading one elment 
    if(x.fail()) sx = abnorm; // if the file reading fail then the status of our program is abnorm
    else sx = norm;
}

/// if used read(); then its implementation is going to be like 
// void infile::read(){
//     m_sx = (m_x >> m_dx) ? norm : abnorm;
// }

void infile::next(){
    if(!(m_end = (m_sx == abnorm))){
        m_curr.count = 0;
        m_curr.number = m_dx;
        while(m_sx == norm && m_dx == m_curr.number){
            m_curr.count += 1;
            read(m_sx, m_dx, m_x);
        }
    }
}


