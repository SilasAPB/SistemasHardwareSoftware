#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t filho;
    int wstatus;

    filho = fork();

    if (filho == 0) {
        printf("Acabei filho\n");
        return 2;
    } else {
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            int retorno = WEXITSTATUS(wstatus);
            printf("Pai: meu filho terminou normalmente com código %d\n", retorno);
        } else {
            printf("Pai: filho terminou de forma anormal!\n");
        }
    }
    return 0;
}
