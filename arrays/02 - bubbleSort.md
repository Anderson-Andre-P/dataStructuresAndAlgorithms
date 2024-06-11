# Bubble Sort

Bubble Sort é um algoritmo que classifica um array do valor mais baixo para o valor mais alto.

A palavra 'Bolha' vem de como esse algoritmo funciona, ele faz com que os valores mais altos 'borbulhem'.

### Como funciona

1. Percorra o array, um valor de cada vez.
2. Para cada valor, compare o valor com o próximo valor.
3. Caso o valor seja maior que o próximo, troque os valores para que o maior valor fique por último.
4. Percorra o array quantas vezes houver valores no array.

## Execução manual

Antes de implementarmos o algoritmo Bubble Sort em uma linguagem de programação, vamos executar manualmente um pequeno array apenas uma vez, só para ter uma ideia.

> [!TIP]
> O primeiro loop foi feito passo a passo (passos 1 a 8), mas para simplificar, após o passo 8 cada passo é um loop.

**Etapa 1:** começamos com um array não classificado.

[7, 12, 9, 11, 3]

**Etapa 2:** analisamos os dois primeiros valores. O valor mais baixo vem primeiro? Sim, então não precisamos trocá-los.

[`7`, `12`, 9, 11, 3]

**Etapa 3:** dê um passo à frente e observe os valores 12 e 9. O valor mais baixo vem primeiro? Não.

[7, `12`, `9`, 11, 3]

**Etapa 4:** então precisamos trocá-los para que 9 venha primeiro.

[7, `9`, `12`, 11, 3]

**Etapa 5:** dar um passo à frente, olhando para 12 e 11.

[7, 9, `12`, `11`, 3]

**Etapa 6:** devemos trocar para que 11 venha antes de 12.

[7, 9, `11`, `12`, 3]

**Etapa 7:** olhando para 12 e 3, precisamos trocá-los? Sim.

[7, 9, 11, `12`, `3`]

**Etapa 8:** Trocando 12 e 3, para que 3 venha primeiro.

[7, 9, 11, `3`, `12`]

**Etapa 8:** Trocando 12 e 3, para que 3 venha primeiro.

[7, 9, 11, `3`, `12`]

**Etapa 9:** Continuando com a próxima iteração, começamos novamente desde o início.

[`7`, `9`, 11, 3, 12]

[7, `9`, `11`, 3, 12]

[7, 9, `11`, `3`, 12]

[7, 9, `3`, `11`, 12]

[`7`, `9`, 3, 11, 12]

**Etapa 10:** Outra iteração.

[7, `9`, `3`, 11, 12]

[7, 3, `9`, `11`, 12]

[7, 3, 9, `11`, `12`]

**Etapa 11:** Mais uma iteração.

[`7`, `3`, 9, 11, 12]

[3, `7`, `9`, 11, 12]

[3, 7, `9`, `11`, 12]

[3, 7, 9, `11`, `12`]

**Etapa 12:** Iteração final.

[`3`, `7`, 9, 11, 12]

[3, `7`, `9`, 11, 12]

[3, 7, `9`, `11`, 12]

[3, 7, 9, `11`, `12`]

[3, 7, 9, 11, `12`]

**Array classificada:** [3, 7, 9, 11, 12]

## Execução manual: o que aconteceu?

Devemos entender o que aconteceu nesta primeira execução para compreender completamente o algoritmo, para que possamos implementá-lo em uma linguagem de programação.

Você consegue ver o que aconteceu com o valor mais alto 12? Ele borbulhou até o final do array, onde pertence. Mas o resto do array permanece sem classificação.

Portanto, o algoritmo Bubble Sort deve percorrer o array novamente, e novamente, e novamente, cada vez que o próximo valor mais alto borbulhar até sua posição correta. A classificação continua até que o valor mais baixo 3 seja deixado no início do array. Isso significa que precisamos percorrer o array 4 vezes para classificar o array de 5 valores.

E cada vez que o algoritmo percorre o array, a parte restante não classificada do array fica mais curta.

## Implementação de classificação por bolha

Para implementar o algoritmo Bubble Sort em uma linguagem de programação, precisamos:

1. Um array para classificar.
2. Um loop interno que percorre o array e troca valores se o primeiro valor for maior que o próximo valor. Este loop deve percorrer um valor a menos cada vez que for executado.
3. Um loop externo que controla quantas vezes o loop interno deve ser executado. Para um array com n valores, esse loop externo deve ser executado n-1 vezes.

O código resultante fica assim:

```c
#include <stdio.h>

int main() {
    int my_array[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (my_array[j] > my_array[j+1]) {
                int temp = my_array[j];
                my_array[j] = my_array[j+1];
                my_array[j+1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    return 0;
}

// output: "Sorted array: 5 11 12 22 25 34 64 90"
```

## Melhoria no Bubble Sort

O algoritmo Bubble Sort pode ser melhorado um pouco mais.

Imagine que o array já está quase ordenado, com os números mais baixos no início, como por exemplo:

```
my_array = [7, 3, 9, 12, 11]
```

Neste caso, o array será ordenado após a primeira execução, mas o algoritmo Bubble Sort continuará a ser executado, sem troca de elementos, e isso não é necessário.

Se o algoritmo passar pelo array uma vez sem trocar nenhum valor, o array deverá ser finalizado e podemos parar o algoritmo, assim:

```c
#include <stdio.h>
#include <stdbool.h>

int main() {
    int my_array[] = {7, 3, 9, 12, 11};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (my_array[j] > my_array[j+1]) {
                int temp = my_array[j];
                my_array[j] = my_array[j+1];
                my_array[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    return 0;
}

// Output: "Sorted array: 3 7 9 11 12"
```

## Complexidade do tempo de execução do Bubble Sort

O algoritmo Bubble Sort percorre cada valor do array, comparando-o com o valor próximo a ele. Portanto, para um array de valores $\ n$, deve haver $\ n$ tais comparações em um loop.

E depois de um loop, o array é repetido repetidamente $\ n$ vezes

Isso significa que há comparações $\ n \times n$ feitas no total, então a complexidade de tempo para Bubble Sort é:

$$\theta(n^2)$$

O gráfico que descreve a complexidade de tempo do Bubble Sort é assim:

<center>
    <img src="../images/arrays/img_runtime_n^2.png" alt="Bubble Sort value complexity">
</center>

Como você pode ver, o tempo de execução aumenta muito rápido quando o tamanho do array aumenta.

Felizmente, existem algoritmos de classificação mais rápidos do que isso, como o Quicksort.
