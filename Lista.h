#ifndef LISTA_H
#define LISTA_H


#include <stdio.h>
#include <stdlib.h>


#define MAX 100


typedef struct {
    int dados[MAX];
    int frente, tras;
} Fila;


Fila* criaFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->frente = 0;
        fila->tras = 0;
    }
    return fila;
}


void destroiFila(Fila* fila) {
    if (fila != NULL) {
        free(fila);
    }
}


int filaVazia(Fila* fila) {
    return (fila->frente == fila->tras);
}


int filaCheia(Fila* fila) {
    return ((fila->tras + 1) % MAX == fila->frente);
}


void enfileira(Fila* fila, int elem) {
    if (!filaCheia(fila)) {
        fila->dados[fila->tras] = elem;
        fila->tras = (fila->tras + 1) % MAX;
    } else {
        printf("Fila cheia. Nao foi possivel enfileirar o elemento.\n");
    }
}


int desenfileira(Fila* fila) {
    int elem = -1;
    if (!filaVazia(fila)) {
        elem = fila->dados[fila->frente];
        fila->frente = (fila->frente + 1) % MAX;
    } else {
        printf("Fila vazia. Nao foi possivel desenfileirar o elemento.\n");
    }
    return elem;
}


void imprimeFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
    } else {
        printf("Elementos da fila: ");
        int i = fila->frente;
        while (i != fila->tras) {
            printf("%d ", fila->dados[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

#endif
