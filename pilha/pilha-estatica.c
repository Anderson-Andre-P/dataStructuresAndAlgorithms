/*
A - O que é uma pilha?O que são pop e push?
Uma pilha pode ser definida como o o empilhamento de processos, ou seja, um processo é colocado em cima do outro para não ficar uma bagunça é utilizado o LIFO (Last In First Out) para organizar os processos e sair o último processo que entrou.
PUSH é a inserção de processos na pilha;
POP é a saída de processos da pilha.

B - Qual a sua importância e aplicabilidade emCiência da Computação?
É importante para manter a organização, pois com as pilhas apenas um item pode ser removido por mês. Além disso as pilhas facilitam a chamada de funções e chamadas de procedimentos.
Uma aplicação de pilha é o ctrl+z, quando alguém aperta o ctrl+z é acionado uma função que retorna para o último item de uma pilha.

C - Descreve brevemente seu funcionamento.
Imagine uma pessoa que trabalha em um restaurante de lavador de pratos, se tiverem 10 pratos um em cima do outro, quando a pessoa for lavar ela precisará retirar o último prato que chegou, se ela tirar o primeiro prato que chegou todos os pratos caem...
*/
#include <stdio.h>
#include <stdlib.h>
// Tamanho máximo da pilha
#define MAX 50

// Estrutura estática
struct pilha
{
    int topo;
    float vet[MAX]; // Aui pode ser char, int, vet[topo]
};

// Define o tipo de dado Pilha
typedef struct pilha Pilha;

// Função que irá retornar a Pilha alocada pelo compilador
Pilha *cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha)); // Maloc aloca

    if (p != NULL)
        p->topo = 0; // Inicializa com zero elementos
    else
        printf("Não há memória suficiente \n");

    return p;
}

// Tamanho da Pilha
int tamanhoPilha(Pilha *p)
{
    if (p == NULL)
        return -1;
    else
        return p->topo;
}

// Verifica se está cheia
int PilhaCheia(Pilha *p)
{
    if (p == NULL)
        return -1;
    return (p->topo == MAX);
}

// Verifica se está vazia
int PilhaVazia(Pilha *p)
{
    if (p == NULL)
        return -1;
    return (p->topo == 0);
}

// Inserindo elementos na Pilha
int pushPilha(Pilha *p, int valor)
{
    // pilha não existe
    if (p == NULL)
        return -1;
    // está cheia - não inserir
    if (p->topo == MAX)
        return -1; // 0
    // Insere no topo
    p->vet[p->topo] = valor;
    // Incrementa o topo
    p->topo++;

    printf("Empilhando Valor: %f \n", p->vet[p->topo - 1]);

    return 1;
}

int popPilha(Pilha *p)
{
    // NULL ou Vazia
    if (p == NULL || p->topo == 0)
        return 0;

    // Apenas Decrementar o topo
    p->topo--;

    printf("Desempilhando Valor: %f \n", p->vet[p->topo]);

    return 1;
}

// Destruir a Pilha e liberar a memória alocada
void liberaPilha(Pilha *p)
{
    free(p);
    printf("Memória Liberada");
}

int main(void)
{
    Pilha *p;
    p = cria();
    // Empilhando
    pushPilha(p, 10);
    pushPilha(p, 20);
    pushPilha(p, 35);
    // desempilhando
    popPilha(p);
    popPilha(p);
    popPilha(p);
    liberaPilha(p);

    return 0;
}