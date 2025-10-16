#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t filho1, filho2, filho3, filho4, filho5, filho6, filho7, filho8;
    pid_t filhos[8] = {filho1, filho2, filho3, filho4, filho5, filho6, filho7, filho8};
    pid_t pai_id = getpid();
    printf("eu sou o processo pai, pid = %d\n", pai_id);

    for (int i = 0; i < 8; i++) {
        filhos[i] = fork();
        if (filhos[i] == 0) {
            pid_t pai_id = getppid();
            pid_t filho = getpid();
            printf("eu sou o processo filho, pid= %d, com pai ppid= %d\n", filho, pai_id);
            break;
        }
    }

    return 0;
}
