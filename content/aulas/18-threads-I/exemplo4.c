
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Two_ints {
    int v1;
    int v2;
}Two_int;

void *tarefa_print_i(void *arg) {
    Two_int *i = (Two_int *)arg;
    printf("Valor 1: %d! E Valor 2: %d!\n", i->v1, i->v2);
    return NULL;
}


int main() {
    Two_int *vi = malloc(4 * sizeof(Two_int));
    pthread_t tid;
    pthread_t *tids = malloc(4 * sizeof(tid));

    for (int i = 0; i < 4; i++) {
        vi[i].v1 = i;
        vi[i].v2 = i*2;
        pthread_create(&tids[i], NULL, tarefa_print_i, &vi[i]);
    }
    printf("Hello main\n");

    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], NULL);
    }
    free(vi);
     free(tids);

    return 0;
}