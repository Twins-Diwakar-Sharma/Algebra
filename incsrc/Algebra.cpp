/*
 * =====================================================================================
 *
 *       Filename:  Algebra.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/2021 04:11:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Algebra.h"

Vec::Vec(int size)
{
    std::cout <<"ctr" << std::endl;
    this->size = size;
    data = new float[size];
    for(int i=0; i<size; i++)
        data[i] = 0;
}

Vec::~Vec()
{
    std::cout << "dtr" << std::endl;
    delete [] data;
}

Vec::Vec(Vec& vec)
{
    std::cout << "cpy" << std::endl;
    size = vec.size;
    data = new float[size];
    for(int i=0; i<size; i++)
        data[i] = vec.data[i]; 
}

Vec::Vec(Vec&& vec)
{
    std::cout << "mv" << std::endl;
    size = vec.size;
    data = vec.data;
    vec.data = nullptr;   
}

Vec& Vec::operator=(Vec& vec)
{
    std::cout << "=" << std::endl;
    size = vec.size;
    data = new float[size];
    for(int i=0; i<size; i++)
        data[i] = vec.data[i];
    return *this;
}

Vec& Vec::operator=(Vec&& vec)
{
    // we need to delete this->data before we replace it with new data to prevent memory leaks
    // so we have to write delete [] this->data,
    // but we can be clever in doing so ..
    // we know that vec is going to be deleted so we point vec.data to content of this->data
    // this we compiler will delete previous data while deleting vec and we dont have to bother

    std::cout << "mv =" << std::endl;
    this->size = vec.size;
    float* toDelete = this->data;
    data = vec.data;
    vec.data = toDelete;
    return *this;
}

float& Vec::operator[](int i)
{
    if(i >= size)
        std::cerr<<"Requested index "<<i<<" out of bounds "<<std::endl;
    else if(i < 0)
        std::cerr<<"negative index ? seriously ? Are you that noob"<<std::endl;
    else 
        return data[i];
}

Vec operator+(Vec& a, Vec& b)
{
    std::cout << "l+l" << std::endl;
    if(a.size != b.size)
    {   
        std::cerr<<"cannot add !! size not same"<<std::endl;
        return NULL;
    }

    Vec v(a.size);
    for(int i=0; i<v.size; i++)
        v[i] = a[i]+b[i];

    return v;
}
 
Vec operator+(Vec& a, Vec&& b)
{
    std::cout << "l+r" << std::endl;
    if(a.size != b.size)
    {   
        std::cerr<<"cannot add !! size not same"<<std::endl;
        return NULL;
    }
    
    for(int i=0; i<a.size; i++)
        b[i] = a[i] + b[i];
    
    return std::move(b);
}
 
Vec operator+(Vec&& a, Vec& b)
{
    std::cout << "r+l" << std::endl;
    if(a.size != b.size)
    {   
        std::cerr<<"cannot add !! size not same"<<std::endl;
        return NULL;
    }
    
    for(int i=0; i<a.size; i++)
        a[i] = a[i] + b[i];
    
    return std::move(a);
}
 
Vec operator+(Vec&& a, Vec&& b)
{
    std::cout << "r+r" << std::endl;
    if(a.size != b.size)
    {   
        std::cerr<<"cannot add !! size not same"<<std::endl;
        return NULL;
    }
    
    for(int i=0; i<a.size; i++)
        b[i] = a[i] + b[i];
   
    return std::move(b);
}


int Vec::getSize()
{
    return size;
}

Vec operator-(Vec& a, Vec& b)
{

    if(a.size != b.size)
    {
        std::cerr << "size of vectors donnot match" << std::endl;
    }
    Vec res(a.size);
    for(int i=0; i<res.size; i++)
    {
        res.data[i] = a.data[i] - b.data[i];
    }
    return res;
}

Vec operator-(Vec& a, Vec&& b)
{
    if(a.size != b.size)
    {
        std::cerr << "size of vectors donnot match" << std::endl;
        return NULL;
    }

    // b is temporary, so we will use it instead
    for(int i=0; i<a.size; i++)
    {
        b.data[i] = a.data[i] - b.data[i];
    }
    return std::move(b);
}

Vec operator-(Vec&& a, Vec& b)
{
    if(a.size != b.size)
    {
        std::cerr << "size of vectors donnot match" << std::endl;
        return NULL;
    }   
    // a is temporary, so we will use it instead
    for(int i=0; i<a.size; i++)
    {
        a.data[i] = a.data[i] - b.data[i];
    }
    return std::move(a);
}

Vec operator-(Vec&& a, Vec&& b)
{
    if(a.size != b.size)
    {
        std::cerr << "size of vectors donnot match" << std::endl;
        return NULL;
    }   
    // a is temporary, so we will use it instead
    for(int i=0; i<a.size; i++)
    {
        a.data[i] = a.data[i] - b.data[i];
    }
    return std::move(a);
}

Vec operator*(float f, Vec& vec)
{
    Vec res(vec.size);
    for(int i=0; i<vec.size; i++)
    {
        res.data[i] = f*vec.data[i];
    }
    return res;
}

Vec operator*(float f, Vec&& vec)
{
    // use temp vec
    for(int i=0; i<vec.size; i++)
    {
        vec.data[i] = f*vec.data[i];
    }
    return std::move(vec);
}

Vec operator*(Vec& v, float f)
{
    Vec res(v.size); 
    for(int i=0; i<v.size; i++)
    {
        res.data[i] = f*v.data[i];
    }
    return res;
}

Vec operator*(Vec&& vec, float f)
{
    // use temp vec
    for(int i=0; i<vec.size; i++)
    {
        vec.data[i] = f*vec.data[i];
    }
    return std::move(vec);
}

Mat::Mat(int row,int col)
{
    this->row = row;
    this->col = col;

    data = new float*[row];
    for(int i=0; i<row; i++)
    {
        data[i] = new float[col];
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            data[i][j] = 0;
        }
    }
}

Mat::~Mat()
{
    for(int i=0; i<row; i++)
        delete [] data[i];

    delete [] data;
}


Mat::Mat(Mat& mat)
{
    this->row = mat.row;
    this->col = mat.col;

    data = new float*[row];
    for(int i=0; i<row; i++)
        data[i] = new float[col];

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            data[i][j] = mat.data[i][j];
}

Mat::Mat(Mat&& mat)
{
    row = mat.row;    col = mat.col; 
    data = mat.data;   
    mat.data = nullptr;
}

Vec operator*(Mat& mat, Vec& vec)
{
    if(mat.col == vec.getSize())
    {
       Vec res(mat.row);
       for(int i=0; i<mat.row; i++)
           for(int j=0; j<mat.col; j++)
               res[i] += vec[j]*mat.data[i][j];
       return res;
    }
    else
    {
        std::cerr << "Matrix and Vector size is not compatible" << std::endl;
        return NULL;
    }
}

Vec operator*(Mat& mat, Vec&& vec)
{
    if(mat.col == vec.getSize())
    {
       Vec res(mat.row);
       for(int i=0; i<mat.row; i++)
           for(int j=0; j<mat.col; j++)
               res[i] += vec[j]*mat.data[i][j];
       return res;
    }
    else
    {
        std::cerr << "Matrix and Vector size is not compatible" << std::endl;
        return NULL;
    }
}

Vec operator*(Mat&& mat, Vec& vec)
{
    if(mat.col == vec.getSize())
    {
       Vec res(mat.row);
       for(int i=0; i<mat.row; i++)
           for(int j=0; j<mat.col; j++)
               res[i] += vec[j]*mat.data[i][j];
       return res;
    }
    else
    {
        std::cerr << "Matrix and Vector size is not compatible" << std::endl;
        return NULL;
    }
}

Vec operator*(Mat&& mat, Vec&& vec)
{
    if(mat.col == vec.getSize())
    {
       Vec res(mat.row);
       for(int i=0; i<mat.row; i++)
           for(int j=0; j<mat.col; j++)
               res[i] += vec[j]*mat.data[i][j];
       return res;
    }
    else
    {
        std::cerr << "Matrix and Vector size is not compatible" << std::endl;
        return NULL;
    }
}



int Mat::getRow()
{
    return row;
}

int Mat::getCol()
{
    return col;
}

void Mat::getDimension(int& r, int& c)
{
    r = row;    c = col;
}

Mat& Mat::operator=(Mat& m)
{
    this->row = m.row;
    this->col = m.col;

    for(int i=0; i<m.row; i++)
        for(int j=0; j<m.col; j++)
            data[i][j] = m.data[i][j];

    return *this;
}

Mat& Mat::operator=(Mat&& m)
{
    this->row = m.row;
    this->col = m.col;

    float** temp = this->data;
    data = m.data;
    m.data = temp;

    return *this;
}

float* Mat::operator[](int i)
{
    if(i<row && i>=0)
        return data[i];
    else
        std::cerr<<"out of bounds exception for row no "<<i<<std::endl;
}

