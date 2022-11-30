
#include<stdio.h>

#include <stdlib.h>
#include <stdbool.h>

#define FracBits 57

typedef long FixedType;
extern int MBPixelCalc(FixedType x, FixedType y);

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
   // printf("\n");
    //see(number);
    //printf("\n");
    //printf("%lu", position);
    //see(1L<<59);
    number = (number | 1L << position);
    return number;
}

float convertBack(FixedType fixedType)
{
    return ((float)fixedType)/(1L<<58);
}

FixedType convertToFixed(double input)
{
    return ((double)input)*(1L<<58);
}

int main(int argc, char* argv[]) {

    double x, y;
    x = atof(argv[1]);
    y = atof(argv[2]);
    long fixedX, fixedY;

    fixedX = convertToFixed(x);
    fixedY = convertToFixed(y);
    //see(fixedX);
    //printf("\n");
    //see(fixedY);
   // printf("\n");
    //long count = MBPixelCalc(fixedX,fixedY);
    //printf("%lf", convertBack(count));
    //see(count);
    printf("MBPixelCalc() returned %d.\n", MBPixelCalc(fixedX,fixedY));
    return 0;
}

/* long count = _MBPixelCalc(fixedX,fixedY);
   see(count);
   printf("\n");
    //printf("%i",count);
  // printf("%li",count);
   //see(count);
   //printf("%lf", convertBack(count));
   printf("\n");
   //see(convertTo(x));*/
//return count;
/*
    int counter =0;
    while(x+y<4&&counter<1000)
    {
        x= x*x;
        y=y*y;
        counter++;
    }


    printf("\n");
    return counter;
*/
// printf("%lf",convertBack((fixedX*fixedX)));
/*
 * idivq %r8
    movq %rax,%r8
    mov %r8, %r11
//computed x^2
    mov %rsi, %rax
    //cqto
    imul %rax
    movq $1, %r9
    sal $57, %r9
    idivq %r9
    movq %rax,%r9
    mov %r9, %r12
    //computed y^2
    addq %r9, %r8
    //added products
    movq $4, %r10
    cmpq %r8, %r10
    jge .Done
.Loop:
    incq %r13
    cmpq %r13, %r14
    je .Done
    mov %r12, %rax
    imul %rax
    movq $1, %r8
    sal $57, %r8
    idivq %r8


     movq %rax, %r8

    mov %r8,%r11
    //xor %rax, %rax
    //xor %rdx, %rdx
    //computed x^2
    mov %rsi, %rax
    //cqto
    imul %rax
    movq $1, %r9
    sal $57, %r9
    idivq %r9
    movq %rax,%r9
    mov %r9, %r12
    //computed y^2
    addq %r9, %r8
    //added products
    movq $4, %r10
    cmpq %r8, %r10
    movq %r11,%rdi
    movq %r12, %rsi
    jl .Loop
.Done:
    movq %r13, %rax
	retq

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
    see(newFixedY);*/
