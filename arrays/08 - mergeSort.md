# Merge Sort

O algoritmo Merge Sort é um algoritmo de divisão e conquista que classifica um array primeiro dividindo-o em arrays menores e, em seguida, construindo o array novamente de maneira correta para que seja classificado.

**Divisão:** o algoritmo começa dividindo o array em pedaços cada vez menores até que uma dessas sub-arrays consista apenas em um elemento.

**Conquista:** o algoritmo mescla os pequenos pedaços do array novamente, colocando os valores mais baixos primeiro, resultando em um array classificado.

A divisão e construção do array para classificá-lo é feita recursivamente.

### Como funciona

1. Divida o array não classificada em duas sub-arrays, com metade do tamanho do original.
2. Continue a dividir as sub-arrays enquanto a parte atual do array tiver mais de um elemento.
3. Mesclar duas sub-arrays, sempre colocando o valor mais baixo primeiro.
4. Continue mesclando até que não haja mais sub-arrays.

A ilustração abaixo mostra como o Merge Sort funciona de uma perspectiva diferente. O array é dividido em pedaços cada vez menores até ser mesclado novamente. E à medida que a fusão aocntece, os valores de cada sub-array são comparados para que o valor mais baixo venha primeiro.

<center>
    <img src="../images/img_mergesort_long.png" alt="Funcionamento do Merge Sort">
</center>

## Execução Manual

Vamos tentar fazer a classificação manualmente, apenas para intender como ele funciona antes de implementá-lo em uma linguagem de programação.

**Etapa 1:** começamos com um array não classificado e sabemos que ele se divide ao meio até que os sub-arrays consistam em apenas um elemento. A função Merge Sort chama a si mesma duas vezes, uma para cada metade do arrya. Isso significa que o primeiro array será subdividida primeiro nos pedaços menores.

[ 12, 8, 9, 3, 11, 5, 4]

[ 12, 8, 9] [ 3, 11, 5, 4]

[ 12] [ 8, 9] [ 3, 11, 5, 4]

[ 12] [ 8] [ 9] [ 3, 11, 5, 4]

**Etapa 2:** a divisão do primeiro array foi concluída e agora é hora de mesclar. 8 e 9 são os dois primeiros elementos a serem mesclados. 8 é o valor mais baixo, portanto vem antes de 9 no primeiro sub-array mesclado.

[ 12] [`8``,9`] [ 3, 11, 5, 4]

**Etapa 3:** os próximos sub-arrays a serem mesclados são [12] e [8, 9]. Os valores em ambos os arrays são comparados cdesde o início. 8 é menor que 12, então vem primeiro e 9 também é menor que 12.

[ `8`,`9`,`12`] [ 3, 11, 5, 4]

**Etapa 4:** agora o segundo grande sub-array é dividido recursivamente.

[ 8, 9, 12] [ 3, 11, 5, 4]

[ 8, 9, 12] [ 3, 11] [ 5, 4]

[ 8, 9, 12] [ 3] [ 11] [ 5, 4]

**Etapa 5:** continuamos a divisão do segundo grande sub-array [3, 11, 5, 4] até que todos os sub-arrays contenham apenas um elemento.

[8, 9, 12] [3, 11] [5, 4]

[8, 9, 12] [3] [11] [5] [4]

**Etapa 6:** começamos a mesclar os sub-arrays [5] e [4]. Comparando os elementos, 4 é menor que 5, então vem antes no sub-array mesclado.

[8, 9, 12] [3] [11] [`4`, `5`]

**Etapa 7:** agora mesclamos os sub-arrays [3] e [11]. Comparando os elementos, 3 é menor que 11, então vem antes no sub-array mesclado.

[8, 9, 12] [`3`, `11`] [4, 5]

**Etapa 8:** em seguida, mesclamos os sub-arrays [3, 11] e [4, 5]. Comparando os elementos, 3 é menor que 4, então vem primeiro. Em seguida, 4 é menor que 11, então vem depois de 3. Finalmente, 5 é menor que 11, então vem depois de 4, seguido por 11.

[8, 9, 12] [`3`, `4`, `5`,`11`]

**Etapa 9:** agora, os dois grandes sub-arrays [8, 9, 12] e [3, 4, 5, 11] são mesclados. Comparando os elementos:

- 3 é menor que 8, então vem primeiro.
- 4 é menor que 8, então vem depois de 3.
- 5 é menor que 8, então vem depois de 4.
- 8 é menor que 11, então vem depois de 5.
- 9 é menor que 11, então vem depois de 8.
- 11 é menor que 12, então vem depois de 9.
- 12 é o último elemento restante.

Assim, temos o array completamente ordenado:

[`3`, `4`, `5`, `8`, `9`, `11`, `12`]

O Merge Sort está completo e o array foi ordenado com sucesso.

## O que aconteceu na execução manual?

É possível observar que o algoritmo possui dois estágios: primeiro a divisão e depois a fusão.

Embora seja possível implementar o algoritmo Merge Sort sem recursão, usaremos recursão porque essa é a abordagem mais comum.

Não podemos ver isso nas etapas acima, mas podemos dividir um array em dois, o comprimento do array é dividido por dois e então arredondado para baixo para obter um valor que chamamos de "mid". Este valor "médio" é utilizado como um índice de onde dividir o array.

Após a divisão do array, a função de classificação chama a si mesma a cada metade, para que o array possa ser dividido novamente recursivamente. A divisão para quando o sub-array consiste apenas em um elemento.

No final da função Merge Sort, os sub-arrays são mesclados para que os sub-arrayssejam sempre classificados à medida que o array é reconstruído. Para unir dois arrays para que o resultado seja classificado, os valores de cada sub-array são comparados e o valor mais baixo é colocado no array mesclado. Depois disso, o próximo valor em cada um dos dois sub-arrays é comparado, colocando o menor no array unido.

## Implementação de Classificação de Mesclagem

Para implementar o algoritmo Merge Sort, precisamos:

1. Um array com valores que precisam ser classificados.
2. Uma função que pega um array, o divide em dois e chama a si mesma com cada metade desse array para que os arrays sejam divididos repetidas vezes recursivamente, até que um sub-array consista apenas em um valor.
3. Outra função que mescla os sub-arrays novamente de forma ordenada.

O código resultante fica assim:

```c
#include <stdio.h>

void mergeSort(double arr[], int start, int end);
void merge(double arr[], int start, int mid, int end);

int main() {
    double unsortedArr[] = {3, 7, 6, -10, 15, 23.5, 55, -13};
    int size = sizeof(unsortedArr) / sizeof(unsortedArr[0]);

    mergeSort(unsortedArr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%.1f ", unsortedArr[i]);
    }
    printf("\n");

    return 0;
}

void mergeSort(double arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(double arr[], int start, int mid, int end) {
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    double left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

//C
```

## Unindo Classificações sem a Recursão

Como Merge Sort é um algoritmo de dividir e conquistar, a recursão é o código mais intuitivo a ser usado para implementação. A implementação recursiva de Merge Sort também é talvez mais fácil de entender e usa menos linhas de código.

Mas Merge Sort também pode ser implementado sem o uso de recursão, de modo que não haja função chamando a si mesma.

```c
#include <stdio.h>
#include <stdlib.h>

void merge(double left[], int leftSize, double right[], int rightSize, double result[]) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        result[k++] = left[i++];
    }

    while (j < rightSize) {
        result[k++] = right[j++];
    }
}

void mergeSort(double arr[], int length) {
    int step = 1;

    while (step < length) {
        for (int i = 0; i < length; i += 2 * step) {
            int leftSize = step;
            int rightSize = step;
            if (i + step >= length) leftSize = length - i;
            if (i + 2 * step >= length) rightSize = length - i - step;

            double left[leftSize];
            double right[rightSize];

            for (int j = 0; j < leftSize; ++j) {
                left[j] = arr[i + j];
            }

            for (int j = 0; j < rightSize; ++j) {
                right[j] = arr[i + step + j];
            }

            double merged[leftSize + rightSize];
            merge(left, leftSize, right, rightSize, merged);

            for (int j = 0; j < leftSize + rightSize; ++j) {
                arr[i + j] = merged[j];
            }
        }

        step *= 2;
    }
}

int main() {
    double arr[] = {3, 7, 6, -10, 15, 23.5, 55, -13};
    int length = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, length);

    printf("Sorted array: ");
    for (int i = 0; i < length; ++i) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");

    return 0;
}

//C
```

Você pode notar que as funções de mesclagem são as mesmas nas duas implementações de Merge Sort, mas na implementação acima, o loop while dentro da função mergeSort é usado para substituir a recursão. O loop while faz a divisão e fusão do array no local, e isso torna o código um pouco mais fácil de entender.

Simplificando o loop while dentro da função mergeSort usa passos curtos para classificar pequenos pedaços (sub-arrays) do array inicial usando a função merge. Em seguida, o comprimento do passo é aumentado para mesclar e classificar partes maiores do array até que todo array seja classificado.

## Complexidade de Tempo de Classificação de Mesclagem

A complexidade de tempo para Merge Sort é: $$O( n \cdot \log n )$$

A complexidade do tempo é praticamente a mesma para diferentes tipos de arrays. O algoritmo precisa dividir o array e mesclá-lo novamente, quer ele seja classificado ou completamente embaralhado.

A imagem abaixo mostra a complexidade de tempo para Merge Sort.

<center>
    <img src="../images/img_runtime_mergesort.png" alt="Runtime Merge Sort">
</center>
