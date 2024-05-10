# Pilha

Uma pilha é uma estrutura de dados linear que segue o princípio LIFO (Last In, First Out), ou seja, o último elemento que entra é o primeiro a sair. Pense em uma pilha de pratos: você adiciona novos pratos no topo e retira do topo também.

## Para que serve:

Pilhas são úteis em situações em que você precisa acessar os elementos em ordem reversa à sua inserção. Elas são utilizadas em várias aplicações, como sistemas de processamento de linguagens (análise sintática), execução de expressões matemáticas, navegação na web (usando o botão "voltar" do navegador) e muitas outras.

## Como funciona:

Uma pilha tem duas operações principais:

1. **Push (Empurrar):** Adiciona um novo elemento no topo da pilha.
2. **Pop (Retirar):** Remove e retorna o elemento que está no topo da pilha.

Além dessas operações, geralmente há uma terceira operação chamada **Top (Topo)**, que apenas retorna o elemento no topo da pilha sem removê-lo.

Internamente, uma pilha pode ser implementada usando uma estrutura de dados como um vetor (array) ou uma lista encadeada. No entanto, o uso mais comum é com um array, devido à facilidade de implementação e ao acesso rápido aos elementos.

Por exemplo, em uma implementação de pilha usando um array, o topo da pilha é indicado pelo índice do último elemento adicionado. Quando você empurra (push) um novo elemento, ele é adicionado nesse índice e o índice é incrementado. Quando você pop um elemento, o índice é decrementado e o elemento é retirado.

Implementando uma pilha em C/C++ usando um algoritmo. Vamos criar uma pilha usando um array para armazenar os elementos.

```cpp
#include <iostream>
using namespace std;

// Definição da estrutura da pilha
#define MAX_SIZE 100 // Tamanho máximo da pilha

struct Stack {
    int top;          // Índice do topo da pilha
    int items[MAX_SIZE]; // Array para armazenar os elementos da pilha
};

// Função para inicializar a pilha
void initializeStack(Stack *stack) {
    stack->top = -1; // Inicializa o índice do topo como -1 (indicando pilha vazia)
}

// Função para verificar se a pilha está vazia
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Função para verificar se a pilha está cheia
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Função para adicionar um elemento no topo da pilha (push)
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        cout << "Erro: a pilha está cheia.\n";
        return;
    }
    stack->items[++stack->top] = value; // Incrementa o topo e adiciona o elemento
}

// Função para remover e retornar o elemento do topo da pilha (pop)
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        cout << "Erro: a pilha está vazia.\n";
        return -1; // Valor de erro, pode ser modificado de acordo com a necessidade
    }
    return stack->items[stack->top--]; // Retorna o elemento do topo e decrementa o topo
}

// Função para retornar o elemento do topo da pilha sem removê-lo (top)
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        cout << "Erro: a pilha está vazia.\n";
        return -1; // Valor de erro, pode ser modificado de acordo com a necessidade
    }
    return stack->items[stack->top]; // Retorna o elemento do topo sem modificar o topo
}

int main() {
    Stack stack;
    initializeStack(&stack);

    // Exemplo de utilização da pilha
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    cout << "Elemento do topo: " << peek(&stack) << endl;

    cout << "Removendo o elemento do topo: " << pop(&stack) << endl;
    cout << "Elemento do topo após remoção: " << peek(&stack) << endl;

    return 0;
}
```

Neste exemplo, criamos uma estrutura `Stack` para representar a pilha, que contém um índice `top` para rastrear o topo da pilha e um array `items` para armazenar os elementos. Em seguida, definimos funções para inicializar a pilha, verificar se está vazia ou cheia, adicionar elementos (push), remover elementos (pop) e obter o elemento do topo (peek).

No `main()`, inicializamos uma pilha, adicionamos alguns elementos usando `push()`, verificamos o elemento do topo usando `peek()`, removemos um elemento usando `pop()` e verificamos o elemento do topo novamente.

## Pilha encadeada

Implementando uma pilha encadeada em C/C++ com um exemplo simples.

```cpp
#include <iostream>
using namespace std;

// Definição da estrutura do nó da pilha
struct Node {
    int data;     // Dado do nó
    Node* next;   // Ponteiro para o próximo nó
};

// Definição da estrutura da pilha
struct Stack {
    Node* top;   // Ponteiro para o topo da pilha
};

// Função para inicializar a pilha
void initializeStack(Stack *stack) {
    stack->top = nullptr; // Inicializa o topo como nullptr (pilha vazia)
}

// Função para verificar se a pilha está vazia
bool isEmpty(Stack *stack) {
    return stack->top == nullptr;
}

// Função para adicionar um elemento no topo da pilha (push)
void push(Stack *stack, int value) {
    // Cria um novo nó
    Node* newNode = new Node;
    newNode->data = value;
    // Define o próximo do novo nó como o atual topo da pilha
    newNode->next = stack->top;
    // Atualiza o topo da pilha para o novo nó
    stack->top = newNode;
}

// Função para remover e retornar o elemento do topo da pilha (pop)
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        cout << "Erro: a pilha está vazia.\n";
        return -1; // Valor de erro, pode ser modificado de acordo com a necessidade
    }
    // Armazena o valor do topo da pilha
    int poppedValue = stack->top->data;
    // Armazena o ponteiro para o nó a ser removido
    Node* temp = stack->top;
    // Atualiza o topo da pilha para o próximo nó
    stack->top = stack->top->next;
    // Libera a memória do nó removido
    delete temp;
    return poppedValue;
}

// Função para retornar o elemento do topo da pilha sem removê-lo (top)
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        cout << "Erro: a pilha está vazia.\n";
        return -1; // Valor de erro, pode ser modificado de acordo com a necessidade
    }
    return stack->top->data; // Retorna o dado do topo da pilha
}

int main() {
    Stack stack;
    initializeStack(&stack);

    // Exemplo de utilização da pilha encadeada
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    cout << "Elemento do topo: " << peek(&stack) << endl;

    cout << "Removendo o elemento do topo: " << pop(&stack) << endl;
    cout << "Elemento do topo após remoção: " << peek(&stack) << endl;

    return 0;
}
```

Neste exemplo, criamos duas estruturas: `Node` para representar cada nó da pilha encadeada e `Stack` para representar a própria pilha. Implementamos funções para inicializar a pilha, verificar se está vazia, adicionar elementos (push), remover elementos (pop) e obter o elemento do topo (peek).

No `main()`, inicializamos uma pilha, adicionamos alguns elementos usando `push()`, verificamos o elemento do topo usando `peek()`, removemos um elemento usando `pop()` e verificamos o elemento do topo novamente.
