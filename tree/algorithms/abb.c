#include <stdio.h>
#include <stdlib.h>
// #include <iostream>

typedef struct no
{
    int valor;
    struct no *direita, *esquerda;
} NoArv;

NoArv *inserir(NoArv *raiz, int num)

{
    if (raiz == NULL)
    {
        if (raiz == NULL)
        {
            NoArv *aux = malloc(sizeof(NoArv));
            aux->valor = num;
            aux->esquerda = NULL;
            aux->direita = NULL;
            return aux;
        }
    }
    else
    {
        if (num < raiz->valor)
            raiz->esquerda = inserir(raiz->esquerda, num);

        else
            raiz->direita = inserir(raiz->direita, num);

        return raiz;
    }
}

void imprimir(NoArv *raiz)
{
    if (raiz)
    {
        printf("%d, ", raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

int main()
{
    NoArv *raiz = NULL; // Inicializando a raiz como NULL

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 100);

    imprimir(raiz);

    return 0;
}
