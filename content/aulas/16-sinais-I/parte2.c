#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    pid_t filho;
    int wstatus;

    filho = fork();
    if (filho == 0) {
        for(;;){
            pid_t pid =getpid();
            printf("Amo entrar em Looping! Meu pid é:%d\n",pid);

        }
    }
    else{

        pid_t pid_filho=wait(&wstatus);
        char *strsig=strsignal(WTERMSIG(wstatus));
        printf("o meu filho de pid %d terminou\n terminou bem: %d\n terminou de maniera abrupta: %d\n, terminou porque: %d\n string: %s",pid_filho,WIFEXITED(wstatus),WIFSIGNALED(wstatus),WTERMSIG(wstatus),strsig);
    }

    return 0;
}