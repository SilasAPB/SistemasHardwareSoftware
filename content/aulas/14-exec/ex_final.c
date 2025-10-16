#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int received = 0;
    int write;
    char buffer[20];

    while (received != 255) {
        printf("Digite um caractere, valor atual %d : ",received);
        scanf("%d", &write); // o espaço ignora ENTERs/espacos
        printf("o numero enviado é %d\n",write);
        sprintf(buffer, "%d", write);
        if (fork() == 0) {
            char prog[] = "./eh_par";
            char *args[] = {"./eh_par", buffer, NULL};
            execvp(prog, args);
            return 10;
        } else {
            int status;
            printf("Esperando o filho acabar!\n");
            wait(&status);
            if (WIFEXITED(status)) {
                // O retorno obtido é da execução do comando ls
                received=WEXITSTATUS(status);
            }
        }
    }
    printf("fim do pai\n");
    return 0;
}