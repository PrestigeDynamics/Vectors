#include <iostream>
#include <stdio.h>
#include "Vector.h"

int main()
{
    Vector v1={1,0,1};
    Vector v2={0,1,0};
    Vector v3={0,0,0};
    Vector v4={0,0,0};

    v3=v1+v2;
    v3*2;
    v3.Vector_Print();

    v4=v1*v2;
    v4.Vector_Print();

    printf("magnitude of v3: %.2f", v3.Vector_MAGNITUDE());

    return 0;
}










