//Fila Sequencial Estatica

#include <stdio.h>
#include "lista.h"


int main() {
    Fila* fila = NULL;
    int opcao, elemento;


    do {
        printf("\nMenu de Opcoes:\n");
        printf("1 - Criar fila\n");
        printf("2 - Enfileirar um item\n");
        printf("3 - Desenfileirar um item\n");
        printf("4 - Imprimir a fila\n");
        printf("5 - Destruir a fila\n");
        printf("6 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);


        switch (opcao) {
            case 1:
                if (fila == NULL) {
                    fila = criaFila();
                    printf("Fila criada com sucesso!\n");
                } else {
                    printf("A fila ja foi criada!\n");
                }
                break;


            case 2:
                if (fila != NULL) {
                    if (!filaCheia(fila)) {
                        printf("Digite o elemento a ser enfileirado: ");
                        scanf("%d", &elemento);
                        enfileira(fila, elemento);
                        printf("Elemento enfileirado com sucesso!\n");
                    } else {
                        printf("Fila cheia. Nao foi possivel enfileirar o elemento.\n");
                    }
                } else {
                    printf("Fila nao criada. Crie a fila primeiro!\n");
                }
                break;


            case 3:
                if (fila != NULL) {
                    int elem = desenfileira(fila);
                    if (elem != -1) {
                        printf("Elemento desenfileirado: %d\n", elem);
                    }
                } else {
                    printf("Fila nao criada. Crie a fila primeiro!\n");
                }
                break;


            case 4:
                if (fila != NULL) {
                    imprimeFila(fila);
                } else {
                    printf("Fila nao criada. Crie a fila primeiro!\n");
                }
                break;


            case 5:
                if (fila != NULL) {
                    destroiFila(fila);
                    fila = NULL;
                    printf("Fila destruida com sucesso!\n");
                } else {
                    printf("Fila nao criada. Crie a fila primeiro!\n");
                }
                break;


            case 6:
                if (fila != NULL) {
                    destroiFila(fila);
                }
                printf("Saindo...\n");
                break;


            default:
                printf("Opcao invalida! Tente novamente.\n");
        }


    } while (opcao != 6);


    return 0;
}
