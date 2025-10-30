
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *tarefa_print_i(void *arg) {
    int *i = (int *)arg;
    printf("Valor: %d!\n", *i);
    return NULL;
}

int main() {
    int *vi = malloc(4 * sizeof(int));
    pthread_t tid;
    pthread_t *tids = malloc(4 * sizeof(tid));

    for (int i = 0; i < 4; i++) {
        vi[i] = i;
        pthread_create(&tids[i], NULL, tarefa_print_i, &vi[i]);
    }
    printf("Hello main\n");

    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], NULL);
        ;
    }
    free(vi);
    free(tids);

    return 0;
}