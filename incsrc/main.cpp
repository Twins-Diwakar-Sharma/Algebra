
#include <iostream>
#include "Algebra.h"

int main()
{
    Vec a(4), b(4);
    for(int i=0; i<4; i++)
    {
	a[i] = i+1;
	b[i] = a[i]*10;
    }

    a = a+std::move(b);
    return 0;
}

