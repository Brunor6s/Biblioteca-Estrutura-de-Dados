#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Livro* cadastrarLivro(Livro *lista) {
    int codigo_teste;
    
    printf("Codigo: ");
    scanf("%d", &codigo_teste);

    if (buscarLivro(lista, codigo_teste) != NULL) {
        printf("\nJa existe um livro cadastrado com o codigo: %d", codigo_teste);
        printf("\nLivro nao cadastrado\n");
        return lista;
    }

 
    Livro *novo = (Livro*) malloc(sizeof(Livro));
    novo->codigo = codigo_teste;

    printf("Titulo: ");
    scanf(" %[^\n]", novo->titulo);

    printf("Autor: ");
    scanf(" %[^\n]", novo->autor);

    printf("Ano: ");
    scanf("%d", &novo->ano);

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);

    novo->prox = lista;
    return novo;
}

Livro* removerLivro(Livro *lista, int codigo) {
    Livro *atual = lista, *ant = NULL;

    while (atual) {
        if (atual->codigo == codigo) {
            if (ant) ant->prox = atual->prox;
            else lista = atual->prox;

            free(atual);
            printf("\nLivro removido do catalogo\n");
            return lista;
        }
        ant = atual;
        atual = atual->prox;
    }

    printf("\nLivro nao encontrado no catalogo\n");
    return lista;
}

Livro* buscarLivro(Livro *lista, int codigo) {
    while (lista) {
        if (lista->codigo == codigo) return lista;
        lista = lista->prox;
    }
    return NULL;
}

void listarLivros(Livro *lista) {
    while (lista) {
        printf("%d - %s | %s | %d | Qtd:%d\n",
            lista->codigo, lista->titulo, lista->autor, lista->ano, lista->quantidade);
        lista = lista->prox;
    }
}

void liberarLista(Livro *lista) {
    Livro *temp;
    while (lista) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}