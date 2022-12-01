.section .data
.section .text
.global MBPixelCalc

MBPixelCalc:
    //movq %rsi, %r15
    movq %rdi, %r10
    //save x0 to r10
    movq %rsi, %r11
    //save y0 to r11
    movq $0, %rdi
    //create iteration variable
    movq $1000, %rsi
    //max iteration
    movq $0, %r8
    //save x
    movq $0, %r9
    //save y
    movq $4, %r15
    //create 4 int to compare the output to
    sal $58, %r15
    //scale the 4 to the fixed type format


.Loop:
     xor %rax,%rax
     xor %rdx, %rdx
     //0 out rax and rdx
     mov %r8, %rax
     movq $1, %r12
     salq $58, %r12
     //create division scale point
     imulq %rax
    //multiply x*x
    idivq %r12
    //divide to scale it to fixed
    movq %rax, %r13
    //saved x*x to r13
    xor %rax,%rax
    xor %rdx, %rdx
    //0 out rax and rdx
    mov %r9, %rax
    //move y to rax
    imulq %rax
    //y*y
    idivq %r12
    //scale y back to fixeddata
    movq %rax, %r14
    //saved y*y to r14
    sub %r14, %r13
    //x*x-y*y
    add %r10,%r13
    //+x0 and save it as xtemp
    mov %r8, %rax
    //move x to rax
    imulq %r9
   // x*y
    idivq %r12
    //scale back
    sal $1,%rax
    //bit shift so 2xy
    adc %r11, %rax
    //add 0y
    movq %rax,%r9
    //save new y
    movq %r13,%r8
    //x = xtemp
    inc %rdi
    //increment iteratior
    mov %r8,%rax
    //copy x to rax
    imulq %rax
    //x*x
    idivq %r12
    //scale back
    movq %rax, %r13
    //save result
   mov %r9,%rax
   // copy y to rax
   imulq %rax
   //y*y
   idivq %r12
   //scalce back
    addq %r13, %rax
    //x*x+y*y
    cmpq %r15,%rax
    //x*x+y*y<=4
    jl .Almost
    //if true jump to and
    jge .Done
    //if not, jump to exit
.Almost:
    cmpq %rsi,%rdi
    //iteration<max iteration
    jl .Loop
    //if true, restart loop
    jge .Done
    //if false jump to exit
.Done:
    movq %rdi, %rax
    //move iteration to rax
    ret
    //return
