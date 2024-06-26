#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 20

typedef int TipoChave;
typedef struct TipoItem
{
    TipoChave Chave;
    /* outros componentes */
} TipoItem;
typedef int TipoIndice;
typedef TipoItem TipoVetor[MAXTAM + 1];

TipoVetor A, B;
TipoIndice i, n;
TipoItem x;
void Refaz(TipoIndice Esq, TipoIndice Dir, TipoItem *A)
{
    TipoIndice i = Esq;
    int j;
    TipoItem x;
    j = i * 2;
    x = A[i];
    while (j <= Dir)
    {
        if (j < Dir)
        {
            if (A[j].Chave < A[j + 1].Chave)
                j++;
        }
        if (x.Chave >= A[j].Chave)
            goto L999;
        A[i] = A[j];
        i = j;
        j = i * 2;
    }
L999:
    A[i] = x;
}
void Constroi(TipoItem *A, TipoIndice *n)
{
    TipoIndice Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1)
    {
        Esq--;
        Refaz(Esq, *n, A);
    }
}

TipoItem Max(TipoItem *A)
{
    return (A[1]);
}

TipoItem RetiraMax(TipoItem *A, TipoIndice *n)
{
    TipoItem Maximo;
    if (*n < 1)
        printf("Erro: heap vazio\n");
    else
    {
        Maximo = A[1];
        A[1] = A[*n];
        (*n)--;
        Refaz(1, *n, A);
    }
    return Maximo;
}

void AumentaChave(TipoIndice i, TipoChave ChaveNova, TipoItem *A)
{
    TipoItem x;
    if (ChaveNova < A[i].Chave)
    {
        printf("Erro: ChaveNova menor que a chave atual\n");
        return;
    }
    A[i].Chave = ChaveNova;
    while (i > 1 && A[i / 2].Chave < A[i].Chave)
    {
        x = A[i / 2];
        A[i / 2] = A[i];
        A[i] = x;
        i /= 2;
    }
}

void Insere(TipoItem *x, TipoItem *A, TipoIndice *n)
{
    (*n)++;
    A[*n] = *x;
    A[*n].Chave = INT_MIN;
    AumentaChave(*n, x->Chave, A);
}

void Imprime(TipoItem *V, TipoIndice *n)
{
    for (i = 1; i <= *n; i++)
        printf("%d ", V[i].Chave);
    putchar('\n');
}

int main(int argc, char *argv[])
{
    TipoItem TEMP;
    n = 7;
    for (i = 1; i <= n; i++)
        scanf("%d", &A[i].Chave);
    /* Teste: 20 15 18 10 12 9 13 */
    printf("Desordenado: ");
    Imprime(A, &n);

    printf("Constroi   : ");
    Constroi(A, &n);
    Imprime(A, &n);

    printf("Aumenta chave posicao 6 para 25: ");
    AumentaChave(6, 25, A);
    Imprime(A, &n);

    x.Chave = 13;
    printf("Insere%3d: ", x.Chave);
    Insere(&x, A, &n);
    Imprime(A, &n);

    TEMP = Max(A);
    printf("Max:%3d\n", TEMP.Chave);

    x = RetiraMax(A, &n);
    printf("Retira%3d: ", x.Chave);
    Imprime(A, &n);
    return (0);
}