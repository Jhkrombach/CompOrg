/* example.c */
#include <stdio.h>

int main(int argc, char *argv[]) {
	extern int MBPixelCalc(long,long);
	printf("MBPixelCalc() returned %d.\n", MBPixelCalc(0,0));
}
