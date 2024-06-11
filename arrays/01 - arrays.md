# Arrays

um array é uma estrutura de dados (DS) usada para armazenar vários elementos.

Arrays são usadas por muitos algoritmos.

Em C/CPP, um array pode ser criado assim:

```c
int my_array[] = {9, 14, 7, 22, 8};
```

Os arrays são indexados, o que significa que cada elemento do array possui um índice, um número que indica onde o elemento está localizado no array. A linguagem de programação neste tutorial (C/CPP) usa indexação baseada em zero para arrays, o que significa que o primeiro elemento de um array pode ser acessado no índice 0.

Em C, este código usa o índice 0 para escrever o primeiro elemento (valor 9) no console:

```c
printf("%d", my_array[0]);
```

Já em C, para imprimir todos os elementos do array, você pode usar este algoritmo abaixo:

```c
#include <stdio.h>

int main() {
    int my_array[] = {9, 14, 7, 22, 8};
    int length = sizeof(my_array) / sizeof(my_array[0]); // Calculate the length of the array

    // Printing the C array
    printf("C array: [");
    for (int i = 0; i < length; i++) {
        printf("%d", my_array[i]);
        if (i < length - 1)
            printf(", ");
    }
    printf("]\n");

    return 0;
}
```

## Algoritmo: Encontre o valor mais baixo em um array

Vamos criar nosso primeiro algoritmo usando o array DS.

Abaixo está o algoritmo para encontrar o número mais baixo em um array.

### Como funciona:

1. Analise os valores do array um por um.
2. Verifique se o valor atual é o mais baixo até o momento e, se for, armazene-o.
3. Depois de observar todos os valores, o valor armazenado será o mais baixo de todos os valores do array.

## Implementação

Antes de implementar o algoritmo usando uma linguagem de programação real, geralmente é inteligente primeiro escrever o algoritmo como um procedimento passo a passo.

Se você puder escrever o algoritmo em algo entre a linguagem humana (pseudocódigo) e a linguagem de programação, o algoritmo será mais fácil de implementar posteriormente porque evitamos nos afogar em todos os detalhes da sintaxe da linguagem de programação.

1. Crie uma variável 'minVal' e defina-a igual ao primeiro valor do array.
2. Percorra cada elemento do array.
3. Se o elemento atual tiver um valor inferior a 'minVal', atualize 'minVal' para este valor.
4. Depois de examinar todos os elementos do array, a variável 'minVal' agora contém o valor mais baixo.

Você também pode escrever o algoritmo de uma forma que se pareça mais com uma linguagem de programação, se desejar, assim:

```
Variable 'minVal' = array[0]
For each element in the array
    If current element < minVal
        minVal = current element
```

Depois de escrevermos o algoritmo, é muito mais fácil implementá-lo em uma linguagem de programação específica:

```c
#include <stdio.h>

int main() {
    int my_array[] = {7, 12, 9, 4, 11};
    int size = sizeof(my_array) / sizeof(my_array[0]);
    int minVal = my_array[0];

    for(int i = 0; i < size; i++) {
        if(my_array[i] < minVal) {
            minVal = my_array[i];
        }
    }

    printf("Lowest value: %d\n", minVal);
    return 0;
}
```

## Complexidade de tempo do algoritmo

Ao explorar algoritmos, frequentemente observamos quanto tempo um algoritmo leva para ser executado em relação ao tamanho do conjunto de dados.

<center>
 <img src="../images/arrays/img_runtime_findlowest.png" alt="Mais baixo valor de complexidade">
</center>

No exemplo acima, o tempo que os algoritmos precisam para ser executados é proporcional, ou linear, ao tamanho do conjunto de dados. Isso ocorre porque o algoritmo deve visitar cada elemento do array uma vez para encontrar o valor mais baixo. O loop deve ser executado 5 vezes, pois existem 5 valores no array. E se o array tivesse 1.000 valores, o loop teria que ser executado 1.000 vezes.
