#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"

int main() {
    Livro *lista = NULL;
    Historico *topo = NULL;

    int op, cod;
    char msg[200];
    Livro *livro;

    do {
        printf("\nEscolha uma opcao a seguir:\n1 - Cadastrar\n2 - Remover do Catalogo\n3 - Remover\n4 - Buscar\n5 - Listar\n6 - Emprestar\n7 - Devolver\n8 - Historico\n0 - Sair\n");
        scanf("%d", &op);

        switch(op) {
       case 1: {

                Livro *lista_anterior = lista; 
                
                lista = cadastrarLivro(lista);
                
                if (lista != lista_anterior) {
                    snprintf(msg, sizeof(msg), "Livro cadastrado: %s", lista->titulo);
                    topo = push(topo, msg);
                    printf("Livro registrado com sucesso\n");
                }
                break;
            }
            case 2:
                printf("Codigo: ");
                scanf("%d", &cod);
                livro = buscarLivro(lista, cod);
                if (livro) {
                    printf("\nRemovendo: %s", livro->titulo);
                    snprintf(msg, sizeof(msg), "Livro removido do catalogo: %s", livro->titulo);
                }else snprintf(msg, sizeof(msg), "Tentativa de remocao: codigo %d nao encontrado", cod);
                lista = removerLivro(lista, cod);
                topo = push(topo, msg);
                break;

            case 3:
                printf("Codigo: ");
                scanf("%d", &cod);
                livro = buscarLivro(lista, cod);
                if (livro && livro->quantidade > 0) {
                    livro->quantidade--;
                    printf("\nRemovido uma unidade do livro: %s\n", livro->titulo);
                    snprintf(msg, sizeof(msg), "Livro removido: %s", livro->titulo);
                    topo = push(topo, msg);
                } else printf("Indisponivel\n");
                break;

            case 4:
                printf("Codigo: ");
                scanf("%d", &cod);
                livro = buscarLivro(lista, cod);
                if (livro) printf("\nEncontrado: %s - %s (%d) Qtd:%d\n",
                    livro->titulo, livro->autor, livro->ano, livro->quantidade);
                else printf("\nNao encontrado\n");
                break;

            case 5:
                printf("\nLivros no Acervo:\n");
                listarLivros(lista);
                break;

            case 6:
                printf("Codigo: ");
                scanf("%d", &cod);
                livro = buscarLivro(lista, cod);
                if (livro && livro->quantidade > 0) {
                    livro->quantidade--;
                    printf("\nEmprestimo realizado do livro: %s\n", livro->titulo);
                    snprintf(msg, sizeof(msg), "Emprestimo realizado: %s", livro->titulo);
                    topo = push(topo, msg);
                } else printf("Indisponivel\n");
                break;

            case 7:
                printf("Codigo: ");
                scanf("%d", &cod);
                livro = buscarLivro(lista, cod);
                if (livro) {
                    livro->quantidade++;
                    printf("\nDevolucao realizada do livro: %s\n", livro->titulo);
                    snprintf(msg, sizeof(msg), "Devolucao realizada: %s", livro->titulo); //Imprimido interno
                    topo = push(topo, msg);
                } else printf("\nNao encontrado\n");
                break;

            case 8:
                printf("\nHistorico topo/recente:\n");
                mostrarHistorico(topo);
                break;
        }

    } while(op != 0);

    liberarLista(lista);
    liberarPilha(topo);
    return 0;
}