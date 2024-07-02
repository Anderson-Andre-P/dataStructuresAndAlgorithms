/*
Esse exercício aqui não entendi muito bem (principalmente a teoria), acho que é porque eu já estou cansado.

A - O que é uma pilha dinâmica?
É quando uma pilha é implementada utilizando o encadeamento.
Os elementos são colocados na lista e a pilha representa um ponteiro que aponta para o 1º nó da lista.

B - Qual a sua vantagem em relação a uma pilha estática?
Esse modo de empilhamento é bom quando não se sabe o número máximo de elementos que serão armazenados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// estrutura com ponteiro próximo
struct no
{
    int valor;
    struct no *prox;
};

// Define o tipo de dado pilha
typedef struct no Pilha;
// Pilhha global
Pilha *p;

// Função que aloca memoria inicial
Pilha *criaPilha(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    return p;
}

// Consulta pilha
int consultaTopo()
{
    if (p == NULL)
        return 0;
    return (p)->valor;
}

void tamanhoPilha()
{
    int tam = -1;
    Pilha *aux = criaPilha();
    aux = p;

    while (aux != NULL)
    {
        aux = aux->prox;
        tam++;
    }
    printf("Tamanho da pilha %d \n", tam);
}

// Inserindo elementos na pilha
int pushPilha(int valor)
{
    // crio um novo NO
    Pilha *elemento = (Pilha *)malloc(sizeof(Pilha));

    if (elemento == NULL)
        return 0;

    // Adiciono o novo elemento no NO
    elemento->valor = valor;
    // Faço o novo NO apontar para o anterior
    elemento->prox = (p);

    // Atualizo o ponteiro da Pilha para o novo NO
    p = elemento;

    printf("Empilhou Valor: %d \n", p->valor);
    return 1;
}

int popPilha()
{
    // Vazia ou NULL
    if (p == NULL)
        return 0;

    printf("Desempilhou Valor: %d \n", p->valor);

    Pilha *elemento = p;
    p = elemento->prox;
    free(elemento);

    return 1;
}

int main(void)
{

    p = criaPilha();
    // Empilhando
    pushPilha(10);
    tamanhoPilha();
    pushPilha(20);
    tamanhoPilha();
    pushPilha(30);
    tamanhoPilha();
    pushPilha(40);
    tamanhoPilha();

    printf("TOPO %d \n", consultaTopo());

    // desempilhando
    popPilha();
    tamanhoPilha();
    popPilha();
    tamanhoPilha();
    popPilha();
    tamanhoPilha();
    popPilha();
    tamanhoPilha();

    return 0;
}