
void ex5(int a, int b, int *div, int *rem) {
    *div = a/b;
    *rem = a%b;
}

int main() {
    int d, r;
    ex5(10, 3, &d, &r);
    return d;
}
