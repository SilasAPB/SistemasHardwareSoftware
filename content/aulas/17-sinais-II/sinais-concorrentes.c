#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
int status = 0;

void operacao_lenta() {
    sleep(10);
}


void sigint_handler(int num) {
    status += 1;
    printf("Chamou Ctrl+C; status=%d\n", status);
    operacao_lenta();
    printf("SIGINT: Vou usar status agora! status=%d\n", status);
}

void sigterm_handler(int num) {
    status += 1;
    printf("Recebi SIGTERM; status=%d\n", status);
    operacao_lenta();
    printf("SIGTERM: Vou usar status agora! status=%d\n", status);
}

int main() {
    /* TODO: registar SIGINT aqui. */
    struct sigaction s;
    s.sa_handler = sigint_handler; // aqui vai a função a ser executada
    sigemptyset(&s.sa_mask);
    sigaddset(&s.sa_mask, SIGTERM);
    s.sa_flags = 0;

    sigaction(SIGINT, &s, NULL);

    /* TODO: registar SIGTERM aqui. */
    struct sigaction t;
    t.sa_handler = sigterm_handler; // aqui vai a função a ser executada
    sigemptyset(&t.sa_mask);
    sigaddset(&t.sa_mask, SIGINT);
    t.sa_flags = 0;

    sigaction(SIGTERM, &t, NULL);

    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}
