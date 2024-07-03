#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct tipoAluno
{
    int matricula;
    char nome[50];
};

typedef struct tipoAluno Elemento;

struct lista
{
    int posElemento;
    // Vetor do tipo elemento (contém dois campos, matrícula e nome)
    Elemento vet[MAX];
};

typedef struct lista Lista;

// Cria um novo aluno do tipo Elemento
Elemento *aluno = (Elemento *)malloc(sizeof(Elemento));

void Iniciar(Lista *L)
{
    // Cria uma lista vazia
    L->posElemento = 0;
}

int Fim(Lista *L)
{
    // Retorna a posição após o último elemento da lista
    return (L->posElemento);
}

int Vazia(Lista *L)
{
    // Retorna 1 se a lista está vazia, 0 caso contrário
    return (L->posElemento == 0);
}

int Cheia(Lista *L)
{
    // Retorna 1 se a lista está cheia, 0 caso contrário
    return (L->posElemento >= MAX);
}

// Insere novo elemento na posição p da Lista.
int Inserir(Elemento *x, int pos, Lista *L)
{
    // variável auxiliar
    int q;

    // Se a lista está cheia não faz sentido inserir
    if (Cheia(L))
        return 0;

    // Se p é maior que fim ou p é negativo não é possível inserir
    if ((pos > Fim(L)) || (pos < 0))
        return 0;

    // q recebe o número do elemento atual
    for (q = L->posElemento; q > pos; q--)
    {
        L->vet[q] = L->vet[q - 1];
    }

    L->posElemento = L->posElemento + 1;
    L->vet[pos] = *x;

    return 1;
}

// Insere novo elemento mantendo a ordem
int inserirOrdenado(Elemento *x, Lista *L)
{
    int i = 0;
    while ((i < L->posElemento) && (x->matricula > L->vet[i].matricula))
    {
        i++;
    }
    return (Inserir(x, i, L));
}

// Remover o elemento na posição pos da Lista
int Remover(int pos, Lista *L)
{
    int i;

    if ((pos >= Fim(L)) || (pos < 0))
        return 0;

    if (Vazia(L))
        return 0;

    for (i = pos + 1; i < L->posElemento; i++)
        L->vet[i - 1] = L->vet[i];

    L->posElemento = L->posElemento - 1;
    return 1;
}

// Buscar elemento
int buscaLinear(Elemento *x, Lista *L)
{
    int i; // posição
    i = 0;
    while ((i < L->posElemento) && (strcmp(x->nome, L->vet[i].nome)))
        i++;
    return i;
}

int main(void)
{
    // Cria a lista
    Lista *L = (Lista *)malloc(sizeof(Lista));
    Iniciar(L);

    // Cria um novo aluno do tipo Elemento
    Elemento *aluno1 = (Elemento *)malloc(sizeof(Elemento));
    aluno1->matricula = 5;
    printf("Entre com o nome do aluno \n");
    scanf("%s", aluno1->nome);

    Inserir(aluno1, 0, L);
    inserirOrdenado(aluno1, L);
}
