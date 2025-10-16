#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int op(int a, int b, int v) {
    if (v == 0) {
        return a + b;
    } else if (v == 1) {
        return a - b;
    } else if (v == 2) {
        return a * b;
    } else {
        return a / b;
    }
}

int main() {
    pid_t filho1, filho2, filho3, filho4;
    pid_t filhos[4] = {filho1, filho2, filho3, filho4};
    int wstatus;
    int num1;
    int num2;

    printf("Coloque dois numeros ");
    scanf("%d %d", &num1, &num2);

    for (int i = 0; i < 4; i++) {
        filhos[i] = fork();
        if (filhos[i] == 0) {
            int resul = op(num1, num2, i);
            printf("O resultado agora é de %d\n", resul);
            return resul;
        }
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            int retorno = WEXITSTATUS(wstatus);
            printf("Pai: meu filho terminou normalmente com código %d\n", retorno);
        }
    }

    return 0;
}