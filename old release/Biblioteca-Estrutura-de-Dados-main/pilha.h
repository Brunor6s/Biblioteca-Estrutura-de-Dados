#ifndef PILHA_H
#define PILHA_H

typedef struct Historico {
    char acao[200];
    struct Historico *prox;
} Historico;

Historico* push(Historico *topo, char acao[]);
void mostrarHistorico(Historico *topo);

Historico* pop(Historico *topo);
void liberarPilha(Historico *topo);

#endif