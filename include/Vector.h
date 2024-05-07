#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <stdio.h>
#define PI 3.14159265
#define RadConv PI/180.0;
#define DegConv 180.0/PI;

class Vector
{
private:
    float x1;
    float x2;
    float x3;
    bool Is3dVector;

public:
    Vector(float x, float y) : x1(x), x2(y)
    {Is3dVector=false;}

    Vector(float x, float y, float z) : x1(x), x2(y), x3(z)
    {Is3dVector=true;}

    ~Vector() {}


    float Vector_MAGNITUDE();
    float Vector_DOTPRODUCT(const Vector);
    float Vector_ANGLEBETWEEN(const Vector, const Vector);
    void Vector_Print();

    void operator * (int x);
    Vector operator + (Vector) const; //vector sum
    Vector operator - (Vector) const; //vector subtraction
    Vector operator * (Vector) const; //Cross product of two vectors
};

#endif // VECTOR_H
