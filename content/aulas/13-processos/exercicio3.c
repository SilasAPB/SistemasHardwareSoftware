#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t filho1, filho2, filho3, filho4;
    int wstatus;
    pid_t pai = getpid();
    printf("eu sou o processo pai, pid= %d\n", pai);
    filho1 = fork();

    if (filho1 == 0) {
        pid_t pai_id = getppid();
        pid_t filho = getpid();
        printf("eu sou o processo filho, pid= %d, com pai ppid= %d\n", filho, pai_id);
        return 1;
    } else if (filho1 > 0) {
        filho2 = fork();
        if (filho2 == 0) {
            filho3 = fork();
            if (filho3 == 0) {
                pid_t pai_id = getppid();
                pid_t filho = getpid();
                printf("eu sou o processo filho, pid= %d, com pai ppid= %d\n", filho, pai_id);
                return 3;
            } else if (filho3 > 0) {
                filho4 = fork();
                if (filho4 == 0) {
                    pid_t pai_id = getppid();
                    pid_t filho = getpid();
                    printf("eu sou o processo filho, pid= %d, com pai ppid= %d\n", filho, pai_id);
                    return 4;
                } else if (filho4 > 0) {
                    for (int i = 0; i < 2; i++) {
                        wait(&wstatus);
                        if (WIFEXITED(wstatus)) {
                            int retorno = WEXITSTATUS(wstatus);
                            printf("Pai: meu filho terminou normalmente com código %d\n", retorno);
                        }
                    }
                    pid_t pai_id = getppid();
                    pid_t filho = getpid();
                    printf("eu sou o processo filho, pid= %d, com pai ppid= %d\n", filho, pai_id);
                    return 2;
                }
            }
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