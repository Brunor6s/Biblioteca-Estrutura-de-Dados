#ifndef LISTA_H
#define LISTA_H

typedef struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidade;
    struct Livro *prox;
} Livro;

Livro* cadastrarLivro(Livro *lista);
Livro* removerLivro(Livro *lista, int codigo);
Livro* buscarLivro(Livro *lista, int codigo);
void listarLivros(Livro *lista);
void liberarLista(Livro *lista);

#endif