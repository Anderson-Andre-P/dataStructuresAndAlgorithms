# Lista

Uma lista é uma estrutura de dados que organiza elementos em uma sequência. Cada elemento na lista é armazenado em um nó (ou célula), e cada nó contém um valor e uma referência ao próximo nó na sequência. Listas são úteis quando a ordem dos elementos é importante e quando há necessidade de inserção ou remoção frequente de elementos no meio da sequência.

## Para que serve?

Listas são úteis para implementar coleções de elementos onde a ordem é crucial e onde há necessidade de inserções ou remoções frequentes em qualquer ponto da coleção. Elas oferecem operações eficientes de inserção e remoção em comparação com estruturas como arrays.

## Como funciona?

Uma lista é uma coleção de elementos organizados em uma sequência. Cada elemento é armazenado em um nó, e cada nó contém um valor e uma referência para o próximo nó na sequência. Isso cria uma estrutura encadeada na qual os elementos podem ser acessados sequencialmente. Para acessar um elemento específico na lista, normalmente começa-se pelo primeiro nó (cabeça) e percorre-se os nós sequencialmente até encontrar o nó desejado ou alcançar o final da lista. Essa estrutura permite inserções e remoções eficientes de elementos em qualquer posição da lista, tornando-a flexível para uma variedade de aplicações.

## Lista estática

Uma lista estática é uma estrutura de dados onde o tamanho da lista é fixo durante toda a execução do programa. Aqui está uma implementação básica de uma lista estática em C++:

```cpp
#include <iostream>

const int MAX_SIZE = 100; // Tamanho máximo da lista

struct StaticList {
    int data[MAX_SIZE];
    int size;
};

// Inicializa a lista
void initList(StaticList& list) {
    list.size = 0;
}

// Insere um elemento na lista
bool insert(StaticList& list, int value) {
    if (list.size >= MAX_SIZE) {
        std::cout << "Lista cheia. Não é possível inserir mais elementos." << std::endl;
        return false;
    }

    list.data[list.size] = value;
    list.size++;
    return true;
}

// Imprime a lista
void printList(const StaticList& list) {
    if (list.size == 0) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }

    std::cout << "Lista: ";
    for (int i = 0; i < list.size; ++i) {
        std::cout << list.data[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    StaticList myList;
    initList(myList);

    // Inserindo elementos na lista
    insert(myList, 10);
    insert(myList, 20);
    insert(myList, 30);

    // Imprimindo a lista
    printList(myList);

    return 0;
}
```

Neste exemplo, a lista estática é implementada como um array de tamanho fixo (`data`) dentro de uma estrutura `StaticList`. A variável `size` rastreia o número de elementos atualmente na lista. A função `initList` inicializa a lista, e a função `insert` insere um elemento na lista. A função `printList` imprime todos os elementos da lista.

## Lista dinâmica

Neste exemplo, foi criado um programa que permite ao usuário inserir elementos em uma lista dinâmica e, em seguida, imprime a lista.

```cpp
#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Função para inicializar a lista
void initList(Node*& head) {
    head = nullptr;
}

// Função para inserir um elemento no final da lista
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para imprimir a lista
void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }

    std::cout << "Lista: ";
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Função para liberar a memória alocada para os nós da lista
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* myList = nullptr;
    initList(myList);

    std::cout << "Digite os elementos da lista (digite -1 para parar):" << std::endl;
    int element;
    do {
        std::cin >> element;
        if (element != -1) {
            insert(myList, element);
        }
    } while (element != -1);

    // Imprimindo a lista
    printList(myList);

    // Liberando a memória alocada para os nós da lista
    clearList(myList);

    return 0;
}
```

Neste exemplo, usamos uma lista dinâmica implementada como uma lista ligada simples. Cada elemento na lista é representado por um nó (`Node`), que armazena o valor do elemento e um ponteiro para o próximo nó na lista. A função `insert` insere um novo elemento no final da lista, a função `printList` imprime todos os elementos da lista, e a função `clearList` libera a memória alocada para os nós da lista.

## Lista ligada

Uma lista ligada em C/C++ é uma estrutura de dados composta por uma sequência de nós, onde cada nó armazena um valor e um ponteiro para o próximo nó na lista. Aqui está um exemplo de algoritmo que demonstra como usar uma lista ligada:

```cpp
#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Função para inicializar a lista
void initList(Node*& head) {
    head = nullptr;
}

// Função para inserir um elemento no início da lista
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Função para imprimir a lista
void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }

    std::cout << "Lista: ";
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Função para liberar a memória alocada para os nós da lista
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* myList = nullptr;
    initList(myList);

    std::cout << "Digite os elementos da lista (digite -1 para parar):" << std::endl;
    int element;
    do {
        std::cin >> element;
        if (element != -1) {
            insert(myList, element);
        }
    } while (element != -1);

    // Imprimindo a lista
    printList(myList);

    // Liberando a memória alocada para os nós da lista
    clearList(myList);

    return 0;
}
```

Neste exemplo, a lista ligada é implementada como uma sequência de nós, onde cada nó contém um valor (`data`) e um ponteiro para o próximo nó (`next`). A função `initList` inicializa a lista, a função `insert` insere um novo elemento no início da lista, a função `printList` imprime todos os elementos da lista e a função `clearList` libera a memória alocada para os nós da lista.

## Lista duplamente ligada

Uma lista duplamente ligada em C/C++ é uma estrutura de dados onde cada nó possui dois ponteiros: um para o próximo nó na sequência e outro para o nó anterior. Aqui está um exemplo de algoritmo que demonstra como usar uma lista duplamente ligada:

```cpp
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Função para inicializar a lista
void initList(Node*& head) {
    head = nullptr;
}

// Função para inserir um elemento no início da lista
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

// Função para imprimir a lista
void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }

    std::cout << "Lista: ";
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Função para liberar a memória alocada para os nós da lista
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* myList = nullptr;
    initList(myList);

    std::cout << "Digite os elementos da lista (digite -1 para parar):" << std::endl;
    int element;
    do {
        std::cin >> element;
        if (element != -1) {
            insert(myList, element);
        }
    } while (element != -1);

    // Imprimindo a lista
    printList(myList);

    // Liberando a memória alocada para os nós da lista
    clearList(myList);

    return 0;
}
```

Neste exemplo, a lista duplamente ligada é implementada como uma sequência de nós, onde cada nó possui três campos: um para o valor do elemento (`data`), um para o ponteiro para o próximo nó (`next`) e um para o ponteiro para o nó anterior (`prev`). A função `initList` inicializa a lista, a função `insert` insere um novo elemento no início da lista, a função `printList` imprime todos os elementos da lista e a função `clearList` libera a memória alocada para os nós da lista.
