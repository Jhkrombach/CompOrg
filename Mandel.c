
#include<stdio.h>

#include <stdlib.h>
#include <stdbool.h>

#define FracBits 57
typedef long FixedType;
extern int _MBPixelCalc(FixedType x, FixedType y);

void see (FixedType n)
{
    long i;
    for(i=63;i>=0;i--)
    {
        long mask = 1L<<i;
        long k = n & mask;
        k==0 ? printf("0") : printf("1");
    }
}


FixedType changeBit(FixedType number, int position, int value)
{
    printf("\n");
    //see(number);
    printf("\n");
    //printf("%lu", position);
    //see(1L<<59);
    number = (number | 1L << position);
    return number;
}

int main(int argc, char* argv[]) {

    double x, y;
    bool isXPositive, isYPositive;
    // sscanf(argv[1],"%lf",&x);
    //   sscanf(argv[2],"%lf",&y);
    x = atof(argv[1]);
    y = atof(argv[2]);
    // printf("%lf", y);
    long fixedX, fixedY;
    //memcpy(&fixedX, &x, sizeof(fixedX));
   // memcpy(&fixedY, &y, sizeof(fixedY));
    if (x >= 0) isXPositive = true;
    else isXPositive = false;
    if (y >= 0) isYPositive = true;
    else isYPositive = false;


    double binaryWorth = 32;
    //1 == -16, 11 = -8, 111, -4, 1110
    double currentWorth = 0;
    FixedType newFixedX = 0;
    //newFixedX = changeBit(newFixedX, 63, 1);

    for (long p = 0; p < 64; p++) {
        long position = 63 - p;
        if (p == 0) {
            if (isXPositive) {
                currentWorth = 0;
            } else {
                newFixedX = changeBit(newFixedX, 63, 1);
               // see(newFixedX);
                currentWorth = -32;
            }
            binaryWorth = binaryWorth / 2;
            continue;
        }
            // 0 = 16, 1= 8, 2= 4 3 =2, 4=1
        else {
            if (currentWorth < 0) //negative number
            {
                //printf("%s", "LOL");
               // printf("%lf\n",currentWorth);
                if (currentWorth + binaryWorth <= x) {
                    //printf("%s", "LOL");
                    newFixedX = changeBit(newFixedX, position, 1);
                    //see(newFixedX);
                    currentWorth = currentWorth + binaryWorth;
                  //  printf("\n%lf", currentWorth);
                  //  continue;
                }
                else
                {
                   // newFixedX = changeBit(newFixedX, position, 0);
                }
            } else {
               // printf("%i",p);
               if(binaryWorth==0) break;
                if (currentWorth + binaryWorth <= x) {
                   // printf("%s","HI");
                    newFixedX = changeBit(newFixedX, position, 1);
                    currentWorth = currentWorth + binaryWorth;
                }
                else
                {
                    //newFixedX = changeBit(newFixedX, position, 0);
                }
            }
        }
        binaryWorth = binaryWorth / 2;
        if(currentWorth==x)
        {
            break;
        }
    }


    FixedType newFixedY = 0;
    double binaryWorthY = 32;
    double currentWorthY=0;
   // see(newFixedY);
    for (long p = 0; p < 64; p++) {
        long position = 63 - p;
        if (p == 0) {
            if (isYPositive) {
                currentWorthY = 0;
            } else {
                newFixedY = changeBit(newFixedY, position, 1);
                // see(newFixedX);
                currentWorthY = -32;
            }
            binaryWorthY = binaryWorthY / 2;
           continue;
        }
            // 0 = 16, 1= 8, 2= 4 3 =2, 4=1
        else {
          //  if(binaryWorthY==0) break;
            if (currentWorthY < 0) //negative number
            {
              //  printf("\n%lf", currentWorthY);
                //printf("%s", "LOL");
                // printf("%lf\n",currentWorth);
                if (currentWorthY + binaryWorthY <= y) {
                    //printf("%lf",binaryWorthY);
                    newFixedY = changeBit(newFixedY, position, 1);
                    //see(newFixedX);
                    currentWorthY = currentWorthY + binaryWorthY;
                    //  printf("\n%lf", currentWorth);
                    //  continue;
                }
                else
                {
                    //printf("%lf",binaryWorthY);
                    //newFixedY = changeBit(newFixedY, position, 0);
                }
            } else {
                // printf("%i",p);
                if (currentWorthY + binaryWorthY <= y) {
                    // printf("%s","HI");
                    newFixedY = changeBit(newFixedY, position, 1);
                    currentWorthY = currentWorthY + binaryWorthY;
                }
                else
                {
                    //newFixedY = changeBit(newFixedY, position, 0);
                }
            }
        }
        binaryWorthY = binaryWorthY / 2;
        if(currentWorthY==y)break;
       // printf("\n%lf", binaryWorthY)
    }
    printf("\n");
    see(newFixedX);
    printf("\n");
    see(newFixedY);
   // int count = _MBPixelCalc(newFixedX,newFixedY);
    /*printf("\n");
    printf("%i",count);
    printf("\n");
    return count;*/
    /*
    int counter =0;
    while(x+y<4&&counter<1000)
    {
        x= x*x;
        y=y*y;
        counter++;
    }

    printf("%i",counter);
    printf("\n");
    return counter;
*/
    return 0;
}

