#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GetBits(x, k, j) (x >> k) & ~((~0) << j)
#define MAXTAM 100000000
#define BASE 256
#define M 8
#define NBITS 32

typedef int TipoIndice;
typedef int TipoChave;

typedef struct TipoItem
{
    TipoChave Chave;
} TipoItem;

typedef TipoItem TipoVetor[MAXTAM + 1];

TipoVetor A;
TipoVetor B;
int C[BASE];

void ContagemInt(TipoItem *A, TipoIndice n, int Pass)
{
    int i, j;
    for (i = 0; i <= BASE - 1; i++)
        C[i] = 0;
    for (i = 1; i <= n; i++)
    {
        j = GetBits(A[i].Chave, Pass * M, M);
        C[j] = C[j] + 1;
    }
    if (C[0] == n)
        return;
    for (i = 1; i <= BASE - 1; i++)
        C[i] = C[i] + C[i - 1];
    for (i = n; i > 0; i--)
    {
        j = GetBits(A[i].Chave, Pass * M, M);
        B[C[j]] = A[i];
        C[j] = C[j] - 1;
    }
    for (i = 1; i <= n; i++)
        A[i] = B[i];
}

void RadixsortInt(TipoItem *A, TipoIndice n)
{
    int i;
    for (i = 0; i < NBITS / M; i++)
        ContagemInt(A, n, i);
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
    int i, n = 10;
    for (i = 1; i <= n; i++)
        A[i].Chave = 1 + rand();
    printf("Desordenado: ");
    Imprime(A, n);
    printf("RadixsortInt ");
    RadixsortInt(A, n);
    Testa(A, n);
    return 0;
}