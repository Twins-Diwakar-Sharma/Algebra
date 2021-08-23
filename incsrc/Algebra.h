#ifndef H_AL_Z3BR0_H
#define H_AL_Z3BR0_H

#include <iostream>

class Vec
{
    private:
        float* data;
        int size;
    public:
        Vec(int size);
        ~Vec();
        Vec(Vec&); // l value copy constructor
        Vec(Vec&&); // r value copy constructor


        Vec& operator=(Vec&&); // r value assignment
        Vec& operator=(Vec&); //l value assignment
};

#endif
