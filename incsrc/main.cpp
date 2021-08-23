





#include <iostream>
#include "Algebra.h"

int main()
{
    
    std::cout << "4 constructors " << std::endl; 
    Vec a(3), b(3), c(3), d(3);

    for(int i=0; i<3; i++)
    {
        a[i] = (i+1);
        b[i] = 10*(i+1);
        c[i] = 100*(i+1);
        d[i] = 1000*(i+1);
    }


    a = a - b - c - d;

    std::cout << "program ends" << std::endl;

    return 0;
}

