int ex1(int a, int b, int c, int d){
    long ret;
    ret=a+b;
    d=ret+4*c;
    a*=a;
    ret=a+2*b;
    c+=ret;
    return (d>=c);
}

   //0x01132 <+0>:    endbr64
   //0x01136 <+4>:    push   %rbx
   //0x01137 <+5>:    mov    %rdi,%rbx
   //0x0113a <+8>:    mov    %rsi,%rdi
   //0x0113d <+11>:   call   0x1129 <vezes2>
   //0x01142 <+16>:   cmp    %rbx,%rax
  // 0x01145 <+19>:   jle    0x114a <ex2+24>
 //  0x01147 <+21>:   add    %rbx,%rbx
  // 0x0114a <+24>:   add    %rbx,%rax
  // 0x0114d <+27>:   pop    %rbx
 //  0x0114e <+28>:   ret 

long vezes2(long a){
    return 2*a;
}

long ex2(long a, long b){
    long c = a;
    a = b;
    long ret = vezes2(a);
    if (c < ret) {
        c += c;
    }
    ret += c;
    return ret;
}


//Dump of assembler code for function ex3:
   //0x000 <+0>:  endbr64
   //0x004 <+4>:  cmp    %rsi,%rdi
   //0x007 <+7>:  setl   %al
   //0x00a <+10>: movzbl %al,%eax
   //0x00d <+13>: mov    %eax,(%rdx)
   //0x00f <+15>: sete   %al
   //0x012 <+18>: movzbl %al,%eax
   //0x015 <+21>: mov    %eax,(%rcx)
   //0x017 <+23>: setg   %al
   //0x01a <+26>: movzbl %al,%eax
   //0x01d <+29>: mov    %eax,(%r8)
   //0x020 <+32>: ret

void ex3 (int a, int b, int* c, int* d, int* e){
    *c=(a<b);
    *d=(a==b);
    *e=(a>b);
}


//Dump of assembler code for function ex4:
   //0x00a <+0>:  endbr64 
   //0x00e <+4>:  cmp    $0x11,%di
   //0x012 <+8>:  jle    0x21 <ex4+23>
   //0x014 <+10>: sub    $0x41,%esi
   //0x017 <+13>: cmp    $0x1,%sil
   //0x01b <+17>: ja     0x29 <ex4+31>
   //0x01d <+19>: lea    -0x11(%rdi),%eax
   //0x020 <+22>: ret    
   //0x021 <+23>: mov    $0x12,%eax
   //0x026 <+28>: sub    %edi,%eax
   //0x028 <+30>: ret    
   //0x029 <+31>: mov    $0xffffffff,%eax
   //0x02e <+36>: ret 

int ex4 (long a, int unsigned b){
    if ((short)a<=17){
        return 18 - a;
    }
    b-=65;
    if ((char)b>1){
        return -1;
    }
    return a-17;
}

int main(){
    return 0;
}