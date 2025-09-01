#include <stdio.h>

int ex4(int a, int b) {
    return a * b + 32;
}

int main() {
    int d = ex4(5, 2);
    int d2 = ex4(2, 2);
    printf("%d\n", d+d2);
    return d;
}
