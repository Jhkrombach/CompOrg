
#include<stdio.h>

#include <stdlib.h>
#include <stdbool.h>

#define FracBits 57

typedef long FixedType;
extern int MBPixelCalc(FixedType x, FixedType y);

void see (FixedType n) //Method for seeing the output of the fixed data type
{
    long i;
    for(i=63;i>=0;i--)
    {
        long mask = 1L<<i;
        long k = n & mask;
        k==0 ? printf("0") : printf("1");
    }
}


double convertBack(FixedType fixedType) //method to turn the fixed data-type back into a float
{
    return ((float)fixedType)/(1L<<58);
}

FixedType convertToFixed(double input) //method to turn the double into a fixedType
{
    return ((double)input)*(1L<<58);
}

int main(int argc, char* argv[]) {

    double x, y;
    x = atof(argv[1]);
    y = atof(argv[2]); //convert the input into a double
    FixedType fixedX, fixedY;

    fixedX = convertToFixed(x); //convert the doubles into a fixed type
    fixedY = convertToFixed(y);
    printf("MBPixelCalc() returned %d.\n", MBPixelCalc(fixedX,fixedY));
    return 0;
}
