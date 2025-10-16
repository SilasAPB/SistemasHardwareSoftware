/*
Dump of assembler code for function first_neg:
   0x0000 <+0>:     mov    $0x0,%eax
   0x0005 <+5>:     cmp    %esi,%eax
   0x0007 <+7>:     jge    0x17 <first_neg+23>
   0x0009 <+9>:     movslq %eax,%rdx
   0x000c <+12>:    cmpl   $0x0,(%rdi,%rdx,4)
   0x0010 <+16>:    js     0x17 <first_neg+23>
   0x0012 <+18>:    add    $0x1,%eax
   0x0015 <+21>:    jmp    0x5 <first_neg+5>
   0x0017 <+23>:    repz retq



int first_neg(int* v, int n){
    int ret =0;
    loop:
    if (ret>=n) goto retorno;
    if (v[(long)ret]<0) goto retorno;
    ret++;
    goto loop;
    retorno:
    return ret;
}
*/

int first_neg(int* v, int n){
    int ret =0;
    while (ret<n && v[(long)ret]>=0){
        ret++;
    }
    return ret;
}

int main(){
    return 0;
}