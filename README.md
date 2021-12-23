# Algebra for Neural Networks
#### C++ Mathematics libraray for creation of dynamic size matrices and vector 

This Library is for creation of variable sized matrix and vector \
You can make any desired size matrices or vectors for various neural network related mathematics
```
Vec v1(20), v2(40);
Mat m1(30,20), m2(30, 40);
```

The library uses operator overloading which makes it an easy to understand and easy to use mathematics library 🥧

```
Vec res = m1*v1 + m2*v2;
Vec diff = m1*v1 - m2*v2;
```
* _The resultant vector will automatically have the size of 30_
* _If matrices or vectors dont have compatible sizes the library throw error_


