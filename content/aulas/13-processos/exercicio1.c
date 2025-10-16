#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t filho1, filho2;
    int wstatus;
    int num;
    printf("digite um numero\n");
    scanf("%d", &num);
    filho1 = fork();

    if (filho1 == 0) {
        printf("o dobro é: %d\n", num * 2);
        return 1;
    } else if (filho1 > 0) {
        filho2 = fork();
        if (filho2 == 0) {
            printf("a metade é: %d\n", num / 2);
            return 2;
        } else if (filho2 > 0) {
            for (int i = 0; i < 2; i++) {
                wait(&wstatus);
                if (WIFEXITED(wstatus)) {
                    int retorno = WEXITSTATUS(wstatus);
                    printf("Pai: meu filho terminou normalmente com código %d\n", retorno);
                }
            }
        } else {
            perror("Erro no segundo fork");
        }
    } else {
        perror("Erro no primeiro fork");
    }
    return 0;
}
