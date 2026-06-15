#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

Historico* push(Historico *topo, char acao[]) {
    Historico *novo = (Historico*) malloc(sizeof(Historico));
    strcpy(novo->acao, acao);
    novo->prox = topo;
    return novo;
}

void mostrarHistorico(Historico *topo) {
    while (topo) {
        printf("%s\n", topo->acao);
        topo = topo->prox;
    }
}

Historico* pop(Historico *topo) {
    if (!topo) return NULL;
    Historico *temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}

void liberarPilha(Historico *topo) {
    while (topo) topo = pop(topo);
}