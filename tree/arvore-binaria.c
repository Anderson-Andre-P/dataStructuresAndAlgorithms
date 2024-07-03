#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o nó
struct no
{
    int chave;
    struct no *esquerda;
    struct no *direita;
};

// Define o tipo No
typedef struct no Arvore;

// Criando estrutura da arvore
Arvore *criaArvore()
{
    Arvore *Raiz = (Arvore *)malloc(sizeof(Arvore));
    Raiz = NULL;
    return Raiz;
}

Arvore *criaNovo(int chave)
{
    Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->chave = chave;
    return novo;
}

Arvore *insere(Arvore *Raiz, Arvore *novo)
{
    if (Raiz == NULL)
        return novo;

    if (novo->chave < Raiz->chave)
        Raiz->esquerda = insere(Raiz->esquerda, novo);

    if (novo->chave > Raiz->chave)
        Raiz->direita = insere(Raiz->direita, novo);

    return Raiz;
}

void exibirEmOrdem(Arvore *Raiz)
{
    if (Raiz != NULL)
    {
        exibirEmOrdem(Raiz->esquerda);
        printf("%d ", Raiz->chave);
        exibirEmOrdem(Raiz->direita);
    }
}

void exibirPreOrdem(Arvore *Raiz)
{
    if (Raiz != NULL)
    {
        printf("%d ", Raiz->chave);
        exibirPreOrdem(Raiz->esquerda);
        exibirPreOrdem(Raiz->direita);
    }
}

void exibirPosOrdem(Arvore *Raiz)
{
    if (Raiz != NULL)
    {
        exibirPosOrdem(Raiz->esquerda);
        exibirPosOrdem(Raiz->direita);
        printf("%d ", Raiz->chave);
    }
}

int main(void)
{
    Arvore *Raiz = criaArvore();
    Arvore *novo;

    novo = criaNovo(10);
    Raiz = insere(Raiz, novo);

    novo = criaNovo(11);
    Raiz = insere(Raiz, novo);

    novo = criaNovo(13);
    Raiz = insere(Raiz, novo);

    novo = criaNovo(5);
    Raiz = insere(Raiz, novo);

    novo = criaNovo(2);
    Raiz = insere(Raiz, novo);

    // Exibir a árvore em diferentes ordens
    printf("Em Ordem: ");
    exibirEmOrdem(Raiz);
    printf("\n");

    printf("Pre Ordem: ");
    exibirPreOrdem(Raiz);
    printf("\n");

    printf("Pos Ordem: ");
    exibirPosOrdem(Raiz);
    printf("\n");

    return 0;
}
