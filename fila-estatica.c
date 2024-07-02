#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define o tamanho máximo da fila

int tamanho = 0; // Variável global para acompanhar o tamanho atual da fila

// Estrutura da fila
struct fila
{
    int vet[MAX];    // Vetor que armazena os elementos da fila
    int inicio, fim; // Índices que indicam o início e o fim da fila
};

typedef struct fila Fila; // Define um novo tipo de dado Fila

Fila q; // Declaração da fila

// Função que inicia a fila como vazia
void criaFila(Fila *q)
{
    q->inicio = 0; // Inicializa o início
    q->fim = 0;    // Inicializa o fim
}

// Função que verifica se a fila está vazia
int filaVazia(Fila *q)
{
    if (tamanho == 0)
    {
        printf("Fila Vazia \n");
        return 1; // Retorna 1 se a fila estiver vazia
    }
    return 0; // Retorna 0 se a fila não estiver vazia
}

// Função que insere um elemento na fila
int inserirElemento(Fila *q, int valor)
{
    if (tamanho == MAX)
    {
        printf("Fila Cheia \n\n");
        return 0; // Retorna 0 se a fila estiver cheia
    }

    q->vet[q->fim] = valor; // Insere o valor no fim da fila
    printf("Inserido %d \n\n", q->vet[q->fim]);
    q->fim++; // Incrementa o índice do fim

    if (q->fim == MAX)
    {
        q->fim = 0; // Volta para o início se atingir o limite do vetor
    }

    tamanho++; // Incrementa o tamanho da fila
    return 1;  // Retorna 1 para indicar sucesso
}

// Função que remove um elemento da fila
int removeElemento(Fila *q)
{
    if (tamanho == 0)
    {
        printf("Fila Vazia \n\n");
        return 0; // Retorna 0 se a fila estiver vazia
    }

    int valor = q->vet[q->inicio]; // Armazena o valor a ser removido
    q->inicio++;                   // Incrementa o índice do início

    if (q->inicio == MAX)
    {
        q->inicio = 0; // Volta para o início se atingir o limite do vetor
    }

    printf("Removido %d \n\n", valor);
    tamanho--;    // Decrementa o tamanho da fila
    return valor; // Retorna o valor removido
}

// Função que limpa a fila
void limpaFila(Fila *q)
{
    q->inicio = 0; // Reinicializa o índice do início
    q->fim = 0;    // Reinicializa o índice do fim
    tamanho = 0;   // Reinicializa o tamanho da fila
}

// Função que imprime os elementos da fila
void imprimeFila(Fila *q)
{
    if (filaVazia(q))
    {
        return; // Sai da função se a fila estiver vazia
    }
    printf("Fila: ");
    int i = q->inicio;
    for (int count = 0; count < tamanho; count++)
    {
        printf("%d ", q->vet[i]); // Imprime cada elemento da fila
        i = (i + 1) % MAX;        // Move para o próximo índice, considerando o comportamento circular
    }
    printf("\n");
}

int main(void)
{
    criaFila(&q);            // Inicializa a fila
    inserirElemento(&q, 10); // Insere o elemento 10
    inserirElemento(&q, 20); // Insere o elemento 20
    inserirElemento(&q, 30); // Insere o elemento 30
    inserirElemento(&q, 40); // Insere o elemento 40
    inserirElemento(&q, 50); // Insere o elemento 50
    inserirElemento(&q, 60); // Tenta inserir o elemento 60, mas a fila está cheia

    imprimeFila(&q); // Imprime os elementos da fila

    removeElemento(&q); // Remove um elemento da fila
    removeElemento(&q); // Remove outro elemento da fila
    removeElemento(&q); // Remove outro elemento da fila
    removeElemento(&q); // Remove outro elemento da fila
    removeElemento(&q); // Remove outro elemento da fila
    removeElemento(&q); // Tenta remover mais um elemento, mas a fila está vazia

    imprimeFila(&q); // Imprime os elementos restantes na fila

    return 0;
}
