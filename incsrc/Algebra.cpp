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
    // we need to delete this->data before we replace it with new ata to prevent memory leaks
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


