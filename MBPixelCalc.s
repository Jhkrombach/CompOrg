.section .data

.section .text
.globl MBPixelCalc

int MBPixelCalc(long x, long y):

	
L1:



	cmp cx,$2
	jge done
	jmp L1
done:
	ret
