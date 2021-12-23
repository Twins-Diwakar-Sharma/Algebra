# Algebra for Neural Networks
### C++ Mathematics libraray for creation of dynamic size matrices and vector 

* #####  __This Library is for creation of variable sized matrix and vector__
* #####  __Elements of both vector and matrics will have _float_ data type__
* #####  __You can make any desired size matrices or vectors for various neural network related mathematics__ 🪐
```
Vec v1(20), v2(40);
Mat m1(30,20), m2(30, 40);
```

* #####  __The library uses operator overloading which makes it an easy to understand and easy to use mathematics library__ 🥧

```
Vec res = m1*v1 + m2*v2;
Vec diff = m1*v1 - m2*v2;
```
_The resultant vector will automatically have the size of 30_ \
_If matrices or vectors dont have compatible sizes the library throw error_ \



* #####  __Ease of Access__ 
To access any element you just need access `[]` operator
```
float a = v1[3];
float b = m1[0][4];
```

## Installation
For installation
* copy [Algebra.h](incsrc/Algebra.h) to your header folder
* copy [Algebra.cpp](incsrc/Algebra.cpp) to your source folder


