
#include <iostream>
#include "Algebra.h"

int main()
{

    Vec a(4), b(4) , c(4), d(4);
    std::cout << "init complete" << std::endl;
    a = a + b + c + d;
    std::cout << "program over" << std::endl;
    return 0;
}

