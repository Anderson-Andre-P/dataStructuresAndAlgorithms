/*
O que é uma Fila dinâmica como é conhecida sua sigla em inglês? ​
Uma fila dinâmica é uma "fila" que perde os dados quando removidos, já na fila circular dinâmica não existe esse problema pois não ocorre a perda de dados.
Sigla em inglês: Queue

Qual a sua vantagem em relação a uma Fila estática?​
Ocupa só o espaço que é estritamente necessário.
*/

#include <stdio.h>
#include <stdlib.h>

// Essa estrutura armazena o valor e o próximo elemento da fila
struct no
{
    int valor;
    struct no *prox;
};

// Definimos um TIPO e chamamos de Elemento
typedef struct no Elemento;

// A estrutura fila irá manter dois ponteiros, um para o início e outro para o fim da fila
struct fila
{
    Elemento *inicio;
    Elemento *fim;
};

// A partir da estrutura fila criamos o TIPO Fila
typedef struct fila Fila;

// Criar uma instância da fila
Fila q;

// Função que inicializa a fila, aloca memória e aponta os ponteiros para NULL
void criaFila(Fila *q)
{
    q = (Fila *)malloc(sizeof(Fila)); // Aloca memória para a estrutura Fila
    q->inicio = NULL;                 // Inicialmente, a fila está vazia, então inicio é NULL
    q->fim = NULL;                    // Inicialmente, a fila está vazia, então fim é NULL
}

// Função que insere elementos na fila
int inserirElemento(Fila *q, int valor)
{
    // Aloca espaço para um novo elemento
    Elemento *p = (Elemento *)malloc(sizeof(Elemento));

    // Verifica se a alocação de memória falhou
    if (p == NULL)
    {
        return 0; // Retorna 0 se não conseguiu alocar memória
    }

    // Atribui o valor ao novo elemento
    p->valor = valor;
    p->prox = NULL; // O novo elemento será o último, então prox é NULL

    // Verifica se a fila está vazia
    if (q->inicio == NULL)
    {
        q->inicio = p; // Se a fila está vazia, o novo elemento é o primeiro
    }
    else
    {
        // Se a fila não está vazia, o último elemento atualiza seu ponteiro prox para o novo elemento
        q->fim->prox = p;
    }

    // Atualiza o ponteiro fim para o novo elemento
    q->fim = p;

    // Imprime o valor inserido na fila
    printf("Inserindo %d \n\n", q->fim->valor);
    return 1; // Retorna 1 para indicar sucesso
}

// Função que remove elementos da fila
int removeElemento(Fila *q)
{
    int valor;

    // Verifica se a fila está vazia
    if (q->inicio == NULL)
    {
        printf("Fila Vazia \n");
        return 0; // Retorna 0 se a fila está vazia
    }

    // Armazena o valor do primeiro elemento
    valor = q->inicio->valor;

    // Ponteiro auxiliar para o primeiro elemento
    Elemento *aux = q->inicio;

    // Atualiza o ponteiro inicio para o próximo elemento
    q->inicio = q->inicio->prox;

    // Libera a memória do antigo primeiro elemento
    free(aux);

    // Imprime o valor removido da fila
    printf("Removendo %d \n\n", valor);
    return valor; // Retorna o valor removido
}

// Função que imprime todos os elementos da fila
void imprimeFila(Fila *q)
{
    Elemento *prox = q->inicio;
    if (q->inicio == NULL)
    {
        printf("FILA VAZIA!\n");
    }
    int pos = 1;
    while (prox != NULL)
    {
        printf("Posição %d da fila: %d \n\n", pos, prox->valor);
        prox = prox->prox;
        pos = pos + 1;
    }

    printf("A fila tem %d posições.\n\n", pos - 1);
}

int main(void)
{
    // Inicializa a fila
    criaFila(&q);

    // Insere elementos na fila
    inserirElemento(&q, 10);
    inserirElemento(&q, 20);
    inserirElemento(&q, 30);
    inserirElemento(&q, 40);
    inserirElemento(&q, 50);
    inserirElemento(&q, 60);

    // Imprime a fila
    imprimeFila(&q);

    // Remove elementos da fila
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);
    removeElemento(&q);

    return 0;
}
