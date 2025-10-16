/*
Dump of assembler code for function soma:
   0x0000 <+0>:     mov    $0x0,%edx
   0x0005 <+5>:     mov    $0x0,%eax
   0x000a <+10>:    jmp    0x15 <soma+21>
   0x000c <+12>:    movslq %edx,%rcx
   0x000f <+15>:    add    (%rdi,%rcx,4),%eax
   0x0012 <+18>:    add    $0x1,%edx
   0x0015 <+21>:    cmp    %esi,%edx
   0x0017 <+23>:    jl     0xc <soma+12>
   0x0019 <+25>:    repz retq
   
   int soma (int* v, int n){
    int i =0;
    int soma=0;
    goto comp;
    loop:
    soma+= v[(long)i];
    i++;
    comp:
    if (i<n) goto loop;
    return soma;
}
*/

int soma (int* v, int n){
    int i =0;
    int soma=0;
    while (i<n){
        soma+= v[(long)i];
        i++;
    }
    return soma;
}

int main(){
    return 0;
}