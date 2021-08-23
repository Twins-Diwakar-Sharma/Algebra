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
    this->size = size;
    data = new float[size];
    for(int i=0; i<size; i++)
        data[i] = 0;
}

Vec::~Vec()
{
    delete [] data;
}

Vec::Vec(Vec& vec)
{
    size = vec.size;
    data = new float[size];
    for(int i=0; i<size; i++)
        data[i] = vec.data[i]; 
}

Vec::Vec(Vec&& vec)
{
    size = vec.size;
    data = vec.data;
    vec.data = nullptr;   
}

Vec& Vec::operator=(Vec& vec)
{
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
