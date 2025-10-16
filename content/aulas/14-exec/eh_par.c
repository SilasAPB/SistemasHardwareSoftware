#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc<2){
        printf("Não há argumentos suficientes\n");
    }else{
        int retorno=0;
        char *arg= argv[1];
        double valor=atof(arg);
        if ((long)valor%2==0){
            retorno++;
        }
        if ((long)valor<0){
            retorno=-1;
        }
        printf("O retorno é %d\n",retorno);
        return retorno;
    }

    return -2;
}