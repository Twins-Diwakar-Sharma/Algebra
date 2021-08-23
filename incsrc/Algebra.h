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
        Vec(Vec&&);

        Vec& operator=(Vec&&);
};

#endif
