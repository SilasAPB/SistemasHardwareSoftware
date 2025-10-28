#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

volatile int count =0;
void sig_handler(int num);
// Fora da main, criamos a função que será nosso handler

void cont_handler(int num) {
    // faz algo aqui
        printf("continuando");
        struct sigaction s;

        s.sa_handler = sig_handler;
        s.sa_flags = 0;
        sigemptyset(&s.sa_mask);

        sigaction(SIGTSTP, &s, NULL);
}
void sig_handler(int num) {
    // faz algo aqui
        printf("finalizando por um tstp");
        struct sigaction s;

        s.sa_handler = cont_handler;
        s.sa_flags = 0;
        sigemptyset(&s.sa_mask);

        sigaction(SIGCONT, &s, NULL);

}

int main() {
    /* Dentro da main, uma das primeiras coisas que fazemos é
    registrar nosso handler */
    struct sigaction s;
    s.sa_handler = sig_handler; // aqui vai a função a ser executada
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;

    sigaction(SIGTSTP, &s, NULL);

    printf("Meu pid: %d\n", getpid());
    
    while(1) {
        sleep(1);
    }
    return 0;
}
