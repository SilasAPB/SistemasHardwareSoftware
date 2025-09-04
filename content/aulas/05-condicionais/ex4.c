// long fun4(int a, int b ){
//     if (b==0) goto f1;
//     return 2* a;
//     f1:
//     return 1* a;
// }

long fun4(int a, int b) {
    long c = 1;
    if (a > 0) {
        c = 2;
    }
    return c * b;
}