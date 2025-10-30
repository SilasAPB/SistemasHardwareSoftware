#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct soma_parcial_args {
    double *vetor;
    int start, end;
};

double soma = 0;
void *soma_parcial(void *_arg) {
    struct soma_parcial_args *spa = _arg;

    for (int i = spa->start; i < spa->end; i++) {
        soma += spa->vetor[i];
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    double *vetor = NULL;
    int n;
    scanf("%d", &n);
    struct soma_parcial_args *vet_aa;

    vetor = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vetor[i]);
    }

    vet_aa = malloc(4 * sizeof(struct soma_parcial_args));
    pthread_t *tids = malloc(4 * sizeof(pthread_t));

    for (int i = 0; i < 4; i++) {
        vet_aa[i].vetor = vetor;
        vet_aa[i].start = i * n / 4;

        if (i == 3) {
            vet_aa[i].end = n;
        } else {
            vet_aa[i].end = (i + 1) * n / 4;
        }
        pthread_create(&tids[i], NULL, soma_parcial, &vet_aa[i]);
    }

    /* TODO: criar thread_t e soma_parcial_args aqui */

    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], NULL);
    }

    /* TODO: esperar pela conclusão*/

    printf("Paralela: %lf\n", soma);

    soma = 0;
    struct soma_parcial_args aa;
    aa.vetor = vetor;
    aa.start = 0;
    aa.end = n;
    soma_parcial(&aa);
    printf("Sequencial: %lf\n", soma);

    return 0;
}
