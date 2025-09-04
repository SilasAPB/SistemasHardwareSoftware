int ex6(long a, long b) {
    if (a <= b)
        goto f1;
    b = a;

f1:
    if (a <= 0)
        goto f2;
    b = -b;

f2:
    return b;
}

// ACIMA A VERSAO GOTO

int ex6(long a, long b) {
    if (a > b) {
        b = a;
    }
    if (a > 0) {
        b = -b;
    }
    return b;
}