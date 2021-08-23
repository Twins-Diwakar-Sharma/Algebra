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
        Vec(Vec&); // l value copy constructor
        Vec(Vec&&); // r value copy constructor
        ~Vec();

        Vec& operator=(Vec&); //l value assignment
        Vec& operator=(Vec&&); // r value assignment

        float& operator[](int i);

        friend Vec operator+(Vec&, Vec&);
        friend Vec operator+(Vec&, Vec&&);
        friend Vec operator+(Vec&&, Vec&);
        friend Vec operator+(Vec&&, Vec&&);

        int getSize();
};

#endif
