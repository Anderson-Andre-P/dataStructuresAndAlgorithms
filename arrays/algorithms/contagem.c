#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXTAM 100000000

typedef int TipoIndice;
typedef int TipoChave;

typedef struct TipoItem
{
    TipoChave Chave;
} TipoItem;

typedef TipoItem TipoVetor[MAXTAM + 1];

TipoVetor A;
TipoVetor B;
int C[MAXTAM];

void Contagem(TipoItem *A, TipoIndice n, int k)
{
    int i;
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (i = 1; i <= n; i++)
        C[A[i].Chave] = C[A[i].Chave] + 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i - 1];
    for (i = n; i > 0; i--)
    {
        B[C[A[i].Chave]] = A[i];
        C[A[i].Chave] = C[A[i].Chave] - 1;
    }
    for (i = 1; i <= n; i++)
        A[i] = B[i];
}

void Copia(TipoItem *Fonte, TipoItem *Destino, TipoIndice n)
{
    int i;
    for (i = 1; i <= n; i++)
        Destino[i] = Fonte[i];
}

void Imprime(TipoItem *V, TipoIndice n)
{
    int i;
    for (i = 1; i <= n; i++)
        printf("%d ", V[i].Chave);
    printf("\n");
}

void Testa(TipoItem *V, TipoIndice n)
{
    int i;
    for (i = 2; i <= n; i++)
    {
        if (V[i].Chave < V[i - 1].Chave)
        {
            printf("ERRO: ");
            Imprime(V, n);
            return;
        }
    }
    printf("OK: ");
    Imprime(V, n);
}

int main(int argc, char **argv)
{
    int n = 10, i, k = n;
    for (i = 1; i <= n; i++)
        A[i].Chave = 1 + rand() % (k);
    printf("Desordenado: ");
    Imprime(A, n);
    printf("Contagem ");
    Contagem(A, n, k);
    Testa(A, n);
    return 0;
}