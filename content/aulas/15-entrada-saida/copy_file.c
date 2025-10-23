/* POSIX headers */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Standard C */
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc<3){
        printf("Não há argumentos suficientes\n");
    }else{
        char buf[100];    // local usado para guardar os dados lidos de arq1
        // teste abrindo o arquivo entrada.txt
        int fd1 = open(argv[1], O_RDONLY);
        int fd2= open(argv[2], O_WRONLY | O_CREAT, 0700);
        int ret = 1;
        while (ret != 0) {
            ret = read(fd1, buf, 100); // ATRINUIR VARIAVEL< SE RETORNAR 0, ACABOU O TEXTO
            if (ret !=0){
                write(fd2, buf, 100);
            }
        }
        close(fd1);
        close(fd2);

    }
    return 0;
}
