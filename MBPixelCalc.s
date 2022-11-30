.section .data
.section .text
.global MBPixelCalc

MBPixelCalc:
    //movq %rsi, %r15
    movq %rdi, %r10
    movq %rsi, %r11
    movq $0, %rdi
    movq $1000, %rsi
    movq $0, %r8
    movq $0, %r9
    movq $4, %r15
    sal $58, %r15
    //r8 = x r9 = y

.Loop:
    //save x0 to r10
    //save y0 to r11
     xor %rax,%rax
     
     xor %rdx, %rdx
     mov %r8, %rax
   movq $1, %r12
   salq $58, %r12

    imulq %rax
    // cqo
    //x*x
   //cqo

   // cmp $0, %rax
    //cmove %rdx,%rax
   // xor %rdx, %rdx
    //movq %rax,%rdx
    idivq %r12
    movq %rax, %r13
    //saved x*x to r13
    xor %rax,%rax
    xor %rdx, %rdx
    mov %r9, %rax
    imulq %rax
    movq %rdx,%rax
    xor %rdx, %rdx
    idivq %r12
    movq %rax, %r14
    //saved y*y to r14
    sub %r14, %r13
   // movq %r14, %rax
    //ret
    //x*x-y*y
    add %r10,%r13
    //movq %r13, %rax
    //+x0 and save it as xtemp


    mov %r8, %rax
    imulq %r9
   // movq %rax,%rdx
    idivq %r12
    //ret
    sal $1,%rax
    adc %r11, %rax
    //ret
    movq %rax,%r9
    movq %r13,%r8
    inc %rdi
   xor %rax,%rax
   xor %rdx, %rdx
       //saved new x and y and incremented iteration
    mov %r8,%rax
    imulq %rax
   // movq %rax,%rdx
    idivq %r12
    //ret
    movq %rax, %r13
    xor %rax, %rax
    xor %rdx, %rdx
    //saved x*x to r13
   mov %r9,%rax
   imulq %rax
   //movq %rdx,%rax
   //xor %rdx, %rdx
   idivq %r12
   //ret
    //saved y*y to r15
    addq %r13, %rax
    //ret
    //ret
    cmpq %r15,%rax
    jl .Almost
    jge .Done
.Almost:
    cmpq %rsi,%rdi
    jl .Loop
    jge .Done
.Done:
    movq %rdi, %rax
    ret

//retq


 //#9 //see the current decimal for x
 //11 is to store x^2
