# Base da DSA

1. **Arrays (Vetores):**

   - Arrays são coleções de elementos do mesmo tipo, armazenados em memória contínua.
   - Permitem acessar elementos através de um índice.
   - Têm tamanho fixo que é definido na declaração.

```cpp
#include <stdio.h>

int main() {
    // Declaração de um array de inteiros com tamanho 5
    int numeros[5];

    // Atribuição de valores ao array
    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;
    numeros[3] = 40;
    numeros[4] = 50;

    // Impressão dos valores do array
    printf("Valores do array numeros:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
```

Neste exemplo:

- Declaramos um array de inteiros chamado `numeros` com tamanho 5.
- Atribuímos valores aos elementos do array usando índices.
- Imprimimos os valores do array usando um loop for para percorrer todos os elementos.

Esse é um exemplo básico de como usar arrays em C/C++. Eles são úteis para armazenar uma coleção de valores do mesmo tipo em uma única estrutura de dados e acessá-los por meio de índices.

2. **Arrays de arrays:**

   - Arrays são vetores multidimensionais, ou seja, podemos criar arrays de arrays.
   - São usadas para representar tabelas de dados com duas ou mais dimensões.
   - Acesso aos elementos é feito utilizando múltiplos índices.

```cpp
#include <stdio.h>

int main() {
    // Declaração de um array 3x3 de inteiros
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Impressão dos valores do array
    printf("Valores do array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

Neste exemplo:

- Declaramos um array 3x3 de inteiros chamada `array`.
- Atribuímos valores aos elementos do array utilizando índices bidimensionais.
- Imprimimos os valores do array utilizando dois loops for, um para as linhas e outro para as colunas.

Esse é um exemplo básico de como usar Arrays em C/C++. Elas são úteis para armazenar dados em uma estrutura bidimensional, como uma tabela, e acessá-los por meio de índices de linha e coluna.

3. **Structs (Estruturas):**

   - Structs são usadas para agrupar diferentes tipos de dados sob um único nome.
   - Permitem criar tipos de dados personalizados.
   - São úteis para representar entidades com múltiplos atributos.

```cpp
#include <stdio.h>

// Definição de uma struct chamada 'Pessoa'
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    // Declaração de uma variável do tipo 'Pessoa'
    struct Pessoa pessoa1;

    // Atribuição de valores aos membros da struct 'pessoa1'
    strcpy(pessoa1.nome, "João");
    pessoa1.idade = 25;
    pessoa1.altura = 1.75;

    // Impressão dos valores atribuídos à struct 'pessoa1'
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);
    printf("Altura: %.2f\n", pessoa1.altura);

    return 0;
}
```

Neste exemplo:

- Definimos uma struct chamada `Pessoa`, que possui três membros: `nome`, `idade` e `altura`.
- No `main()`, declaramos uma variável `pessoa1` do tipo `Pessoa`.
- Atribuímos valores aos membros da struct `pessoa1`.
- Imprimimos os valores atribuídos à struct `pessoa1`.

Esse exemplo demonstra como usar structs para agrupar diferentes tipos de dados sob um único nome e acessá-los posteriormente.

4. **Ponteiros:**

   - Ponteiros são variáveis que armazenam endereços de memória.
   - Permitem manipular diretamente a memória do computador.
   - São usados para alocar memória dinamicamente e para criar estruturas de dados mais complexas.

```cpp
#include <stdio.h>

int main() {
    int num = 10; // Declaração de uma variável inteira
    int *ptr;     // Declaração de um ponteiro para inteiro

    ptr = &num;   // Atribui o endereço de memória de 'num' ao ponteiro 'ptr'

    printf("O valor de num: %d\n", num);     // Imprime o valor de 'num'
    printf("O endereço de num: %p\n", &num); // Imprime o endereço de 'num'
    printf("O valor de num acessado pelo ponteiro: %d\n", *ptr); // Imprime o valor de 'num' acessado pelo ponteiro

    return 0;
}
```

Neste exemplo:

- `num` é uma variável inteira que armazena o valor 10.
- `ptr` é um ponteiro para inteiro.
- `ptr = &num;` atribui o endereço de memória da variável `num` ao ponteiro `ptr`.
- `*ptr` acessa o valor armazenado na memória apontada por `ptr`, que é o valor de `num`.

Ao compilar e executar este código, você verá a saída que mostra o valor de `num`, o endereço de `num` e o valor de `num` acessado pelo ponteiro `ptr`. Isso ilustra o conceito de ponteiros em C/C++.

5. **TAD (Tipo Abstrato de Dados):**

   - TAD é uma abstração que define um conjunto de operações sobre um tipo de dado.
   - Esconde os detalhes de implementação dos dados.
   - Exemplos de TAD incluem pilhas, filas, listas, entre outros.

Abaixo vamos implementar uma estrutura de dados para representar uma pilha (stack). Uma pilha é uma estrutura de dados onde o último elemento inserido é o primeiro a ser removido, seguindo o princípio LIFO (Last In, First Out).

```cpp
#include <stdio.h>
#include <stdlib.h>

// Definição do tipo de dado para os elementos da pilha
typedef struct Elemento {
    int dado;
    struct Elemento *proximo;
} Elemento;

// Definição da estrutura da pilha
typedef struct {
    Elemento *topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

// Função para empilhar um elemento na pilha
void empilhar(Pilha *pilha, int valor) {
    Elemento *novoElemento = (Elemento*)malloc(sizeof(Elemento));
    if (novoElemento == NULL) {
        printf("Erro: Não foi possível alocar memória para novo elemento.\n");
        exit(EXIT_FAILURE);
    }
    novoElemento->dado = valor;
    novoElemento->proximo = pilha->topo;
    pilha->topo = novoElemento;
}

// Função para desempilhar um elemento da pilha
int desempilhar(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha vazia, não é possível desempilhar.\n");
        exit(EXIT_FAILURE);
    }
    int valorDesempilhado = pilha->topo->dado;
    Elemento *temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    return valorDesempilhado;
}

int main() {
    Pilha minhaPilha;
    inicializarPilha(&minhaPilha);

    // Empilhando alguns elementos
    empilhar(&minhaPilha, 10);
    empilhar(&minhaPilha, 20);
    empilhar(&minhaPilha, 30);

    // Desempilhando e imprimindo os elementos
    printf("Elementos desempilhados: %d, %d, %d\n", desempilhar(&minhaPilha), desempilhar(&minhaPilha), desempilhar(&minhaPilha));

    return 0;
}
```

Neste exemplo:

- Definimos a estrutura `Elemento`, que representa cada elemento da pilha, contendo um dado e um ponteiro para o próximo elemento.
- Definimos a estrutura `Pilha`, que mantém um ponteiro para o topo da pilha.
- Implementamos funções para inicializar a pilha, verificar se ela está vazia, empilhar um elemento e desempilhar um elemento.
- No `main()`, inicializamos uma pilha, empilhamos alguns elementos e então desempilhamos e imprimimos esses elementos.

Esse exemplo ilustra como podemos implementar um TAD em C/C++ para representar uma pilha, escondendo os detalhes de implementação e fornecendo uma interface para manipular a estrutura de dados.
