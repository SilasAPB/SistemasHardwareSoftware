// Dump of assembler code for function soma_2n:
// 0x066a <+0>:     mov    $0x1,%eax
// 0x066f <+5>:     jmp    0x676 <soma_2n+12>
// 0x0671 <+7>:     shr    %edi
// 0x0673 <+9>:     add    $0x1,%eax
// 0x0676 <+12>:    cmp    $0x1,%edi
// 0x0679 <+15>:    ja     0x671 <soma_2n+7>
// 0x067b <+17>:    repz   retq

int soma_2n(int unsigned a) {
    int ret = 1;
    goto compara;
loop:
    a = a >> 1;
    ret++;
compara:
    if (a > 1) {
        goto loop;
    }
    return ret;
}

int soma_2n(int unsigned a) {
    int ret = 1;
    while (a > 1) {
        a = a >> 1;
        ret++;
    }
    return ret;
}

//  EX. 2

/*
Dump of assembler code for function soma_n:
   0x000 <+0>:  endbr64
   0x004 <+4>:  mov    $0x0,%eax
   0x009 <+9>:  mov    $0x0,%edx
   0x00e <+14>: cmp    %edi,%eax
   0x010 <+16>: jge    0x1d <soma_n+29>
   0x012 <+18>: movslq %eax,%rcx
   0x015 <+21>: add    %rcx,%rdx
   0x018 <+24>: add    $0x1,%eax
   0x01b <+27>: jmp    0xe <soma_n+14>
   0x01d <+29>: mov    %rdx,%rax
   0x020 <+32>: ret
*/

long soma_n(int i) {
    int ret = 0;
    long x = 0;
    long y;
comp:
    if (ret >= i)
        goto fim;
    y = ret;
    x += y;
    ret++;
    goto comp;
fim:
    return x;
}

long soma_n(int i) {
    int ret = 0;
    long x = 0;
    while (ret < i) {
        x += ret;
        ret++;
    }
    return x;
}


// EX 3.


/*

Dump of assembler code for function ex3:
   0x000 <+0>:  endbr64 
   0x004 <+4>:  mov    $0x0,%ecx
   0x009 <+9>:  mov    $0x0,%r8d
   0x00f <+15>: jmp    0x15 <ex3+21>
   0x011 <+17>: add    $0x1,%rcx
   0x015 <+21>: cmp    %rdi,%rcx
   0x018 <+24>: jge    0x2c <ex3+44>
   0x01a <+26>: mov    %rcx,%rax
   0x01d <+29>: cqto   
   0x01f <+31>: idiv   %rsi
   0x022 <+34>: test   %rdx,%rdx
   0x025 <+37>: jne    0x11 <ex3+17>
   0x027 <+39>: add    %rcx,%r8
   0x02a <+42>: jmp    0x11 <ex3+17>
   0x02c <+44>: mov    %r8,%rax
   0x02f <+47>: ret

*/


long ex3(long a, long b){
    int v1=0;
    int v2=0;
    int resto;
    goto l1;
    loop:
    v1++;
    l1:
    if ((long)v1>=a) goto l2;
    resto=v1%b;
    if(resto!=0) goto loop;
    v2+=v1;
    goto loop;
    l2:
    return (long) v2;
}

long ex3(long a, long b){
    int step=0;
    int ret=0;
    while((long)step<a){
        if (step%b==0){
           ret+=step;   
        }
        step++;
    }
    return ret;
}

