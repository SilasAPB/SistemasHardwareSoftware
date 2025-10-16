#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc<2){
        printf("Não há argumentos suficientes\n");
    }else{
        int soma=0;
        for (int i = 0; i < argc; i++) {
            char *arg= argv[i];
            double valor=atof(arg);
            soma+=valor;
        }
        printf("A soma é %d\n",soma);
    }

    return 0;
}