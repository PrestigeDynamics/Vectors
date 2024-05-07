#include "Vector.h"

void Vector::operator * (int x)
{
    x1=x1*x;
    x2=x2*x;
    if(Is3dVector){
        x3=x*x3;
    }
}

Vector Vector::operator + (Vector v2) const
{
    float componentx1=x1+v2.x1;
    float componentx2=x2+v2.x2;

    if(Is3dVector){
        float componentx3=x3+v2.x3;
        return Vector(componentx1, componentx2, componentx3);
    }

    return Vector(componentx1, componentx2);
}

Vector Vector::operator - (Vector v2) const
{
    float componentx1=x1-v2.x1;
    float componentx2=x2-v2.x2;

    if(Is3dVector){
        float componentx3=x3-v2.x3;
        return Vector(componentx1, componentx2, componentx3);
    }
    return Vector(componentx1, componentx2);
}

Vector Vector::operator * (Vector v2) const
{
    if(v2.Is3dVector==true){
        float componentx1=x2*v2.x3-x3*v2.x2;
        float componentx2=x3*v2.x1-x1*v2.x3;
        float componentx3=x1*v2.x2-x2*v2.x1;
        return Vector(componentx1, componentx2, componentx3);
        }
    else{
        printf("WARNING: Cross product is only defined for vectors in 3d");
    }
}

float Vector::Vector_DOTPRODUCT(const Vector v2){ //using the component definition of dot product
    if(Is3dVector){
        float dotsum=(x1*v2.x1)+(x2*v2.x2)+(x3*v2.x3);
        return dotsum;
        }

    float dotsum=(x1*v2.x1)+(x2*v2.x2); return dotsum;
    }

float Vector::Vector_MAGNITUDE(){
    if(Is3dVector){
        float v1Magnitude=sqrt((x1*x1)+(x2*x2)+(x3*x3));
        return v1Magnitude;
        }

    float v1Magnitude=sqrt((x1*x1)+(x2*x2)); return v1Magnitude;}

float Vector::Vector_ANGLEBETWEEN(const Vector v1, const Vector v2) //Return the angle between two vectors using the cos definition of dot product
    {
        float radians=v1.Vector_DOTPRODUCT(v2)/(v1.Vector_MAGNITUDE()*v2.Vector_MAGNITUDE());
        float angle=acos(radians);
        return angle*DegConv;
    }

void Vector::Vector_Print() //print components of vectors
    {
        if (Is3dVector){ printf("x1=%.2f x2=%.2f x3=%.2f\n", x1, x2, x3); }

        else { printf("x1=%.2f x2=%.2f\n", x1, x2); }
    }
