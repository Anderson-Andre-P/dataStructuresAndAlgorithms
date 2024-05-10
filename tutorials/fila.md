# Fila

Uma fila é uma estrutura de dados linear que segue o princípio "primeiro a entrar, primeiro a sair" (FIFO - First In, First Out). Ela funciona de maneira semelhante a uma fila em um supermercado: o primeiro elemento que entra na fila é o primeiro a ser atendido e removido da fila.

Em termos de implementação em C/C++, uma fila pode ser representada usando um array ou uma lista encadeada.

## Fila encadeada

Uma fila encadeada é uma estrutura de dados em que cada elemento da fila é um nó que contém um valor e um ponteiro para o próximo nó na fila. Ao contrário da implementação com array, em uma fila encadeada não há limitação no tamanho da fila, pois os nós são alocados dinamicamente conforme necessário.

Aqui está um exemplo de implementação de uma fila encadeada em C++:

```cpp
#include <iostream>

using namespace std;

// Definição da estrutura do nó da fila
struct Node {
    int data;
    Node* next;
};

class FilaEncadeada {
private:
    Node* frente; // Ponteiro para o primeiro nó da fila
    Node* fundo;  // Ponteiro para o último nó da fila

public:
    // Construtor
    FilaEncadeada() {
        frente = nullptr;
        fundo = nullptr;
    }

    // Verifica se a fila está vazia
    bool vazia() {
        return frente == nullptr;
    }

    // Insere um elemento no final da fila
    void enfileirar(int valor) {
        Node* novoNode = new Node; // Aloca memória para o novo nó
        novoNode->data = valor;
        novoNode->next = nullptr;

        // Se a fila estiver vazia, o novo nó será tanto o primeiro quanto o último
        if (vazia()) {
            frente = novoNode;
            fundo = novoNode;
        } else {
            // Caso contrário, o novo nó é adicionado ao final e o ponteiro de fundo é atualizado
            fundo->next = novoNode;
            fundo = novoNode;
        }
    }

    // Remove e retorna o elemento do início da fila
    int desenfileirar() {
        if (vazia()) {
            cout << "Fila vazia. Impossível desenfileirar.\n";
            return -1; // Retorna um valor padrão caso a fila esteja vazia
        }
        int valorRemovido = frente->data;
        Node* temp = frente; // Armazena temporariamente o nó da frente
        frente = frente->next; // Atualiza o ponteiro da frente para o próximo nó
        delete temp; // Libera a memória do nó removido
        return valorRemovido;
    }

    // Retorna o elemento do início da fila sem removê-lo
    int frenteFila() {
        if (vazia()) {
            cout << "Fila vazia.\n";
            return -1; // Retorna um valor padrão caso a fila esteja vazia
        }
        return frente->data;
    }
};

int main() {
    FilaEncadeada fila;

    // Exemplo de uso da fila encadeada
    fila.enfileirar(10);
    fila.enfileirar(20);
    fila.enfileirar(30);

    cout << "Elemento do início da fila: " << fila.frenteFila() << endl;

    cout << "Removendo elemento do início da fila: " << fila.desenfileirar() << endl;

    cout << "Novo elemento do início da fila: " << fila.frenteFila() << endl;

    return 0;
}
```

Neste exemplo, cada nó da fila contém um valor inteiro (`data`) e um ponteiro para o próximo nó (`next`). A fila é representada pelos ponteiros `frente` (apontando para o primeiro nó da fila) e `fundo` (apontando para o último nó da fila). As operações de enfileirar, desenfileirar e verificar o elemento do início da fila são implementadas de acordo com as características de uma fila encadeada.

## Fila circular

Uma fila circular é uma variação da fila em que os elementos são armazenados em uma estrutura de dados circular. Isso significa que o último elemento da fila aponta de volta para o primeiro, formando um ciclo. Isso permite que a fila seja implementada de forma eficiente usando um array, já que não é necessário mover elementos quando a fila "dá a volta".

Aqui está um exemplo de implementação de uma fila circular em C++:

```cpp
#include <iostream>

using namespace std;

#define MAX_SIZE 5 // Define o tamanho máximo da fila circular

class FilaCircular {
private:
    int frente, fundo;
    int elementos[MAX_SIZE];

public:
    FilaCircular() {
        frente = -1;
        fundo = -1;
    }

    // Verifica se a fila está vazia
    bool vazia() {
        return frente == -1;
    }

    // Verifica se a fila está cheia
    bool cheia() {
        return (fundo + 1) % MAX_SIZE == frente;
    }

    // Insere um elemento no final da fila
    void enfileirar(int valor) {
        if (cheia()) {
            cout << "Fila cheia. Impossível enfileirar.\n";
            return;
        }
        if (vazia())
            frente = 0;
        fundo = (fundo + 1) % MAX_SIZE;
        elementos[fundo] = valor;
    }

    // Remove e retorna o elemento do início da fila
    int desenfileirar() {
        if (vazia()) {
            cout << "Fila vazia. Impossível desenfileirar.\n";
            return -1; // Retorna um valor padrão caso a fila esteja vazia
        }
        int elemento = elementos[frente];
        if (frente == fundo) {
            frente = -1;
            fundo = -1;
        } else {
            frente = (frente + 1) % MAX_SIZE;
        }
        return elemento;
    }

    // Retorna o elemento do início da fila sem removê-lo
    int frenteFila() {
        if (vazia()) {
            cout << "Fila vazia.\n";
            return -1; // Retorna um valor padrão caso a fila esteja vazia
        }
        return elementos[frente];
    }
};

int main() {
    FilaCircular fila;

    // Exemplo de uso da fila circular
    fila.enfileirar(10);
    fila.enfileirar(20);
    fila.enfileirar(30);

    cout << "Elemento do início da fila: " << fila.frenteFila() << endl;

    cout << "Removendo elemento do início da fila: " << fila.desenfileirar() << endl;

    cout << "Novo elemento do início da fila: " << fila.frenteFila() << endl;

    return 0;
}
```

Neste exemplo, a fila circular é implementada usando um array de tamanho fixo `elementos[]`. Os ponteiros `frente` e `fundo` indicam respectivamente o início e o fim da fila. Quando a fila está vazia, ambos os ponteiros são inicializados como -1. Os métodos `enfileirar()`, `desenfileirar()` e `frenteFila()` são implementados para manipular a fila circular de acordo com as operações padrão. A operação de incremento do ponteiro `fundo` é feita de forma circular usando o operador `%`, permitindo que a fila dê a volta quando chega ao final.

## Fila de prioridades

Uma fila de prioridades é uma estrutura de dados na qual cada elemento possui uma prioridade associada e os elementos são removidos da fila com base nessa prioridade. Elementos com maior prioridade são removidos antes dos elementos com menor prioridade, independentemente da ordem de chegada.

Uma maneira comum de implementar uma fila de prioridades é usando uma estrutura de dados chamada de heap, que é uma árvore binária especial onde cada nó é maior (ou menor, dependendo da implementação) do que seus filhos. Esta estrutura permite que o elemento com maior (ou menor) prioridade esteja sempre na raiz da árvore, permitindo operações de inserção e remoção eficientes.

Aqui está um exemplo de implementação de uma fila de prioridades usando um heap em C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class FilaPrioridades {
private:
    vector<int> heap; // Representação do heap como um vetor

    // Funções auxiliares para manter as propriedades do heap
    void subir(int index) {
        while (index > 0) {
            int pai = (index - 1) / 2;
            if (heap[pai] < heap[index])
                break;
            swap(heap[index], heap[pai]);
            index = pai;
        }
    }

    void descer(int index) {
        int n = heap.size();
        while (2 * index + 1 < n) {
            int filhoEsq = 2 * index + 1;
            int filhoDir = 2 * index + 2;
            int menorFilho = filhoEsq;
            if (filhoDir < n && heap[filhoDir] < heap[filhoEsq])
                menorFilho = filhoDir;
            if (heap[index] <= heap[menorFilho])
                break;
            swap(heap[index], heap[menorFilho]);
            index = menorFilho;
        }
    }

public:
    // Insere um elemento na fila de prioridades
    void enfileirar(int valor) {
        heap.push_back(valor);
        subir(heap.size() - 1);
    }

    // Remove e retorna o elemento com maior prioridade da fila de prioridades
    int desenfileirar() {
        if (heap.empty()) {
            cout << "Fila de prioridades vazia.\n";
            return -1; // Retorna um valor padrão caso a fila esteja vazia
        }
        int maxPrioridade = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        descer(0);
        return maxPrioridade;
    }

    // Retorna o elemento com maior prioridade sem removê-lo da fila de prioridades
    int frenteFila() {
        if (heap.empty()) {
            cout << "Fila de prioridades vazia.\n";
            return -1; // Retorna um valor padrão caso a fila esteja vazia
        }
        return heap[0];
    }

    // Verifica se a fila de prioridades está vazia
    bool vazia() {
        return heap.empty();
    }
};

int main() {
    FilaPrioridades fila;

    // Exemplo de uso da fila de prioridades
    fila.enfileirar(10);
    fila.enfileirar(30);
    fila.enfileirar(20);

    cout << "Elemento com maior prioridade: " << fila.frenteFila() << endl;

    cout << "Removendo elemento com maior prioridade: " << fila.desenfileirar() << endl;

    cout << "Novo elemento com maior prioridade: " << fila.frenteFila() << endl;

    return 0;
}
```

Neste exemplo, a fila de prioridades é implementada usando um vetor para representar o heap. Os métodos `subir()` e `descer()` são usados para manter a propriedade do heap após inserções e remoções, garantindo que o elemento com maior prioridade esteja sempre na raiz do heap. As operações de inserção, remoção e consulta da frente da fila de prioridades são implementadas de acordo com as características de um heap.

## Deque (double-ended queue)

Um deque (double-ended queue) é uma estrutura de dados que permite a inserção e remoção de elementos tanto no início quanto no final da fila. Isso o torna muito versátil, pois pode ser usado em situações em que você precisa acessar os elementos tanto pela frente quanto pelo final da fila.

Em C++, você pode implementar um deque usando a classe `std::deque` da biblioteca padrão.

Aqui está um exemplo de implementação e uso de um deque em C++:

```cpp
#include <iostream>
#include <deque>

using namespace std;

int main() {
    // Criação de um deque
    deque<int> meuDeque;

    // Inserção de elementos no final do deque
    meuDeque.push_back(10);
    meuDeque.push_back(20);
    meuDeque.push_back(30);

    // Inserção de elementos no início do deque
    meuDeque.push_front(5);
    meuDeque.push_front(2);

    // Acesso aos elementos do deque
    cout << "Elementos do deque: ";
    for (int i = 0; i < meuDeque.size(); ++i) {
        cout << meuDeque[i] << " ";
    }
    cout << endl;

    // Remoção do elemento do final do deque
    meuDeque.pop_back();

    // Remoção do elemento do início do deque
    meuDeque.pop_front();

    // Acesso aos elementos do deque após a remoção
    cout << "Elementos do deque após remoção: ";
    for (int i = 0; i < meuDeque.size(); ++i) {
        cout << meuDeque[i] << " ";
    }
    cout << endl;

    // Acesso ao primeiro e último elemento do deque
    cout << "Primeiro elemento do deque: " << meuDeque.front() << endl;
    cout << "Último elemento do deque: " << meuDeque.back() << endl;

    return 0;
}
```

Neste exemplo, um deque é criado usando a classe `std::deque`. Elementos são inseridos tanto no final (`push_back`) quanto no início (`push_front`) do deque. Em seguida, os elementos são acessados usando o operador de índice (`[]`) e as funções `front()` e `back()` para acessar o primeiro e o último elemento, respectivamente. Finalmente, elementos são removidos tanto do final (`pop_back`) quanto do início (`pop_front`) do deque.
