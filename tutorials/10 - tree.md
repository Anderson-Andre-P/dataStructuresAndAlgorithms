# Tree (Árvores)

As árvores são amplamente utilizadas em várias áreas da computação devido à sua capacidade de representar relações hierárquicas de forma eficiente. Aqui estão algumas aplicações comuns:

1. **Estruturas de dados**: As árvores são usadas para implementar várias estruturas de dados, como árvores binárias de busca, árvores AVL, árvores de segmentos, entre outras. Elas oferecem operações eficientes de busca, inserção e remoção.

2. **Organização de dados hierárquicos**: Em bancos de dados, as árvores são usadas para representar a estrutura hierárquica de dados, como sistemas de arquivos em um sistema operacional, organizações empresariais, categorias em sites de comércio eletrônico, entre outros.

3. **Algoritmos de busca e otimização**: Algoritmos de busca em árvores são amplamente utilizados em problemas de otimização, inteligência artificial, aprendizado de máquina, entre outros. Exemplos incluem árvores de decisão em aprendizado de máquina e algoritmos de busca em grafos.

4. **Compressão de dados**: Em compressão de dados, as árvores são usadas em algoritmos como Huffman para criar códigos de comprimento variável que minimizam o tamanho dos dados comprimidos.

O funcionamento básico de uma árvore é que ela tem um nó especial chamado de "nó raiz" a partir do qual todos os outros nós são acessíveis. Cada nó pode ter zero ou mais nós filhos, dependendo do tipo de árvore. Os nós que não têm filhos são chamados de "folhas". A profundidade de um nó em uma árvore é a distância entre esse nó e a raiz. A altura da árvore é a profundidade máxima de qualquer nó na árvore.

É importante notar que existem vários tipos de árvores, como árvores binárias, árvores binárias de busca, árvores AVL, árvores B, entre outras, cada uma com suas próprias propriedades e aplicações específicas.

## Binary Tree

Aqui está um exemplo básico de uma implementação de uma árvore binária em C++:

```cpp
#include <iostream>

using namespace std;

// Definição da estrutura do nó da árvore
struct Node {
    int data;
    Node* left;
    Node* right;

    // Construtor para criar um novo nó com um valor específico
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Função para inserir um novo nó na árvore
Node* insertNode(Node* root, int value) {
    // Se a árvore estiver vazia, retorna um novo nó com o valor
    if (root == nullptr) {
        return new Node(value);
    }

    // Se o valor for menor que o valor do nó atual, insere à esquerda
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    // Se o valor for maior que o valor do nó atual, insere à direita
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Função para imprimir os nós da árvore em ordem (in-order traversal)
void printInOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    // Inicializa uma árvore binária vazia
    Node* root = nullptr;

    // Insere alguns valores na árvore
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);

    // Imprime os nós da árvore em ordem
    cout << "Árvore binária em ordem: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
```

Neste exemplo, `Node` é uma estrutura que representa um nó na árvore, contendo um valor (`data`) e ponteiros para os nós filhos esquerdo (`left`) e direito (`right`). A função `insertNode` insere um novo valor na árvore, mantendo a propriedade da árvore binária. A função `printInOrder` realiza uma travessia in-order da árvore, imprimindo os valores dos nós em ordem crescente.

## Binary Search Tree

Claro! Uma Binary Search Tree (BST) é uma árvore binária especial em que cada nó tem uma chave única e as chaves em nós da subárvore esquerda são menores que a chave no nó raiz, enquanto as chaves na subárvore direita são maiores que a chave no nó raiz. Isso permite uma busca eficiente dos elementos na árvore.

Aqui está um exemplo de implementação de uma BST em C++:

```cpp
#include <iostream>

using namespace std;

// Definição da estrutura do nó da árvore
struct Node {
    int key;
    Node* left;
    Node* right;

    // Construtor para criar um novo nó com uma chave específica
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

// Função para inserir uma nova chave na BST
Node* insert(Node* root, int key) {
    // Se a árvore estiver vazia, retorna um novo nó com a chave
    if (root == nullptr) {
        return new Node(key);
    }

    // Caso contrário, percorre a árvore para encontrar o local correto para inserir a chave
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    // Retorna o ponteiro para o nó raiz atualizado
    return root;
}

// Função para buscar uma chave na BST
bool search(Node* root, int key) {
    // Se a árvore estiver vazia ou a chave estiver no nó raiz, retorna verdadeiro
    if (root == nullptr || root->key == key) {
        return root != nullptr;
    }

    // Se a chave for menor que a chave no nó raiz, busca na subárvore esquerda
    if (key < root->key) {
        return search(root->left, key);
    }

    // Se a chave for maior que a chave no nó raiz, busca na subárvore direita
    return search(root->right, key);
}

int main() {
    // Inicializa uma BST vazia
    Node* root = nullptr;

    // Insere algumas chaves na BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    // Busca algumas chaves na BST
    cout << "Chave 20 encontrada na BST: " << boolalpha << search(root, 20) << endl;
    cout << "Chave 60 encontrada na BST: " << boolalpha << search(root, 60) << endl;

    return 0;
}
```

Neste exemplo, `Node` é uma estrutura que representa um nó na árvore, contendo uma chave (`key`) e ponteiros para os nós filhos esquerdo (`left`) e direito (`right`). A função `insert` insere uma nova chave na BST, mantendo a propriedade de ordenação. A função `search` busca uma chave na BST, retornando verdadeiro se a chave for encontrada e falso caso contrário.

## B-Tree

Uma B-Tree é uma estrutura de dados em árvore balanceada, projetada especialmente para sistemas de armazenamento e bancos de dados, onde é necessário acessar rapidamente grandes quantidades de dados em disco. Ela difere das árvores binárias por permitir que cada nó tenha mais de dois filhos, resultando em uma estrutura mais ampla e rasa.

Aqui está um exemplo de implementação básica de uma B-Tree em C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Definição da ordem da B-Tree (o número máximo de filhos de cada nó)
const int ORDER = 3;

// Definição da estrutura do nó da B-Tree
struct Node {
    vector<int> keys;
    vector<Node*> children;
    bool isLeaf;

    // Construtor para criar um novo nó
    Node(bool leaf) {
        isLeaf = leaf;
    }
};

// Função para inserir uma chave na B-Tree
Node* insert(Node* root, int key) {
    // Se a árvore estiver vazia, cria um novo nó folha com a chave
    if (root == nullptr) {
        Node* newNode = new Node(true);
        newNode->keys.push_back(key);
        return newNode;
    }

    // Encontra o índice correto para inserir a chave
    int i = 0;
    while (i < root->keys.size() && key > root->keys[i]) {
        i++;
    }

    // Se este nó é uma folha, insere a chave aqui
    if (root->isLeaf) {
        root->keys.insert(root->keys.begin() + i, key);
    }
    // Caso contrário, insere recursivamente na subárvore apropriada
    else {
        root->children[i] = insert(root->children[i], key);
    }

    // Se o nó está cheio, divide-o
    if (root->keys.size() >= ORDER) {
        // Cria um novo nó que será o irmão direito do nó atual
        Node* newRightNode = new Node(root->isLeaf);

        // Move a metade das chaves e filhos para o novo nó
        newRightNode->keys.assign(root->keys.begin() + ORDER/2 + 1, root->keys.end());
        root->keys.resize(ORDER/2);

        if (!root->isLeaf) {
            newRightNode->children.assign(root->children.begin() + ORDER/2 + 1, root->children.end());
            root->children.resize(ORDER/2 + 1);
        }

        // Atualiza os links entre os nós
        Node* parent = new Node(false);
        parent->keys.push_back(newRightNode->keys[0]);
        parent->children.push_back(root);
        parent->children.push_back(newRightNode);

        return parent;
    }

    return root;
}

// Função para imprimir as chaves da B-Tree em ordem
void printInOrder(Node* root) {
    if (root != nullptr) {
        for (int i = 0; i < root->keys.size(); ++i) {
            if (!root->isLeaf) {
                printInOrder(root->children[i]);
            }
            cout << root->keys[i] << " ";
        }
        if (!root->isLeaf) {
            printInOrder(root->children[root->keys.size()]);
        }
    }
}

int main() {
    // Inicializa uma B-Tree vazia
    Node* root = nullptr;

    // Insere algumas chaves na B-Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 30);

    // Imprime as chaves da B-Tree em ordem
    cout << "Chaves na B-Tree em ordem: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
```

Neste exemplo, `Node` é uma estrutura que representa um nó na B-Tree, contendo um vetor de chaves (`keys`) e um vetor de ponteiros para os filhos (`children`). A função `insert` insere uma chave na B-Tree, mantendo a estrutura balanceada da árvore. Se um nó exceder a capacidade máxima, ele é dividido em dois nós.

## B+ Tree

Uma B+ Tree é uma variação da estrutura de dados B-Tree, otimizada para sistemas de armazenamento em disco. Ela compartilha muitas características com a B-Tree, mas possui algumas diferenças importantes, como ter todas as chaves de dados armazenadas apenas nas folhas, enquanto os nós internos contêm apenas chaves de indexação.

Aqui está um exemplo de implementação básica de uma B+ Tree em C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Definição da ordem da B+ Tree (o número máximo de filhos de cada nó)
const int ORDER = 3;

// Definição da estrutura do nó da B+ Tree
struct Node {
    vector<int> keys;
    vector<Node*> children;
    Node* next; // Ponteiro para o próximo nó folha
    bool isLeaf;

    // Construtor para criar um novo nó
    Node(bool leaf) {
        isLeaf = leaf;
        next = nullptr;
    }
};

// Função para inserir uma chave na B+ Tree
Node* insert(Node* root, int key) {
    // Se a árvore estiver vazia, cria um novo nó folha com a chave
    if (root == nullptr) {
        Node* newNode = new Node(true);
        newNode->keys.push_back(key);
        return newNode;
    }

    // Encontra o índice correto para inserir a chave
    int i = 0;
    while (i < root->keys.size() && key > root->keys[i]) {
        i++;
    }

    // Se este nó é uma folha, insere a chave aqui
    if (root->isLeaf) {
        root->keys.insert(root->keys.begin() + i, key);
    }
    // Caso contrário, insere recursivamente na subárvore apropriada
    else {
        root->children[i] = insert(root->children[i], key);
    }

    // Se o nó está cheio, divide-o
    if (root->keys.size() >= ORDER) {
        // Cria um novo nó que será o irmão direito do nó atual
        Node* newRightNode = new Node(root->isLeaf);

        // Move a metade das chaves e filhos para o novo nó
        newRightNode->keys.assign(root->keys.begin() + ORDER/2, root->keys.end());
        root->keys.resize(ORDER/2);

        if (!root->isLeaf) {
            newRightNode->children.assign(root->children.begin() + ORDER/2, root->children.end());
            root->children.resize(ORDER/2);
        }

        // Atualiza os links entre os nós
        newRightNode->next = root->next;
        root->next = newRightNode;

        return newRightNode;
    }

    return root;
}

// Função para imprimir as chaves da B+ Tree em ordem
void printInOrder(Node* root) {
    if (root != nullptr) {
        for (int i = 0; i < root->keys.size(); ++i) {
            if (!root->isLeaf) {
                printInOrder(root->children[i]);
            }
            cout << root->keys[i] << " ";
        }
        if (!root->isLeaf) {
            printInOrder(root->children[root->keys.size()]);
        }
    }
}

int main() {
    // Inicializa uma B+ Tree vazia
    Node* root = nullptr;

    // Insere algumas chaves na B+ Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 30);

    // Imprime as chaves da B+ Tree em ordem
    cout << "Chaves na B+ Tree em ordem: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
```

Neste exemplo, a estrutura `Node` representa um nó na B+ Tree. Cada nó interno armazena chaves de indexação e ponteiros para os filhos, enquanto os nós folha armazenam apenas chaves de dados. A função `insert` insere uma chave na B+ Tree, mantendo-a balanceada. Se um nó estiver cheio após a inserção, ele é dividido em dois nós.

## B\* Tree

Uma B\* Tree é uma variação da estrutura de dados B-Tree, que é otimizada para minimizar a fragmentação do espaço em disco. Ela compartilha muitas características com a B-Tree, mas possui algumas diferenças sutis em como os nós são divididos e balanceados.

Aqui está um exemplo de implementação básica de uma B\* Tree em C++:

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Definição da ordem da B* Tree (o número máximo de filhos de cada nó)
const int ORDER = 4;

// Definição da estrutura do nó da B* Tree
struct Node {
    vector<int> keys;
    vector<Node*> children;
    bool isLeaf;

    // Construtor para criar um novo nó
    Node(bool leaf) {
        isLeaf = leaf;
    }
};

// Função para inserir uma chave na B* Tree
Node* insert(Node* root, int key) {
    // Se a árvore estiver vazia, cria um novo nó folha com a chave
    if (root == nullptr) {
        Node* newNode = new Node(true);
        newNode->keys.push_back(key);
        return newNode;
    }

    // Encontra o índice correto para inserir a chave
    int i = 0;
    while (i < root->keys.size() && key > root->keys[i]) {
        i++;
    }

    // Se este nó é uma folha, insere a chave aqui
    if (root->isLeaf) {
        root->keys.insert(root->keys.begin() + i, key);
    }
    // Caso contrário, insere recursivamente na subárvore apropriada
    else {
        root->children[i] = insert(root->children[i], key);
    }

    // Se o nó está cheio, divide-o
    if (root->keys.size() >= ORDER) {
        // Cria um novo nó que será o irmão direito do nó atual
        Node* newRightNode = new Node(root->isLeaf);

        // Move a metade das chaves e filhos para o novo nó
        newRightNode->keys.assign(root->keys.begin() + ORDER/2, root->keys.end());
        root->keys.resize(ORDER/2);

        if (!root->isLeaf) {
            newRightNode->children.assign(root->children.begin() + ORDER/2, root->children.end());
            root->children.resize(ORDER/2);
        }

        return newRightNode;
    }

    return root;
}

// Função para imprimir as chaves da B* Tree em ordem
void printInOrder(Node* root) {
    if (root != nullptr) {
        for (int i = 0; i < root->keys.size(); ++i) {
            if (!root->isLeaf) {
                printInOrder(root->children[i]);
            }
            cout << root->keys[i] << " ";
        }
        if (!root->isLeaf) {
            printInOrder(root->children[root->keys.size()]);
        }
    }
}

int main() {
    // Inicializa uma B* Tree vazia
    Node* root = nullptr;

    // Insere algumas chaves na B* Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 30);

    // Imprime as chaves da B* Tree em ordem
    cout << "Chaves na B* Tree em ordem: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
```

Neste exemplo, a estrutura `Node` representa um nó na B* Tree. Assim como na B-Tree, os nós internos contêm chaves de indexação e ponteiros para os filhos, enquanto os nós folha contêm apenas chaves de dados. A função `insert` insere uma chave na B* Tree, mantendo-a balanceada. Se um nó estiver cheio após a inserção, ele é dividido em dois nós.

## AVL Tree

Uma AVL Tree é uma árvore binária de busca balanceada, projetada para manter-se sempre balanceada, garantindo que a altura da árvore seja mantida em um valor ótimo. Isso significa que a diferença entre as alturas das subárvores esquerda e direita de cada nó (chamada de fator de balanceamento) é no máximo 1.

Aqui está um exemplo de implementação básica de uma AVL Tree em C++:

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

// Definição da estrutura do nó da AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    // Construtor para criar um novo nó
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Função para obter a altura de um nó
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Função para calcular o fator de balanceamento de um nó
int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Função para realizar a rotação simples à direita
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza as alturas
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Retorna o novo nó raiz
    return x;
}

// Função para realizar a rotação simples à esquerda
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza as alturas
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Retorna o novo nó raiz
    return y;
}

// Função para inserir uma chave na AVL Tree
Node* insert(Node* root, int key) {
    // Insere a chave como em uma árvore de busca binária padrão
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else { // A chave já existe
        return root;
    }

    // Atualiza a altura do nó atual
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Calcula o fator de balanceamento deste nó
    int balance = getBalanceFactor(root);

    // Caso 1: Rotação simples à direita
    if (balance > 1 && key < root->left->key) {
        return rotateRight(root);
    }

    // Caso 2: Rotação simples à esquerda
    if (balance < -1 && key > root->right->key) {
        return rotateLeft(root);
    }

    // Caso 3: Rotação dupla à esquerda
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Caso 4: Rotação dupla à direita
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    // Retorna o nó raiz sem alterações
    return root;
}

// Função para imprimir as chaves da AVL Tree em ordem
void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->key << " ";
        printInOrder(root->right);
    }
}

int main() {
    // Inicializa uma AVL Tree vazia
    Node* root = nullptr;

    // Insere algumas chaves na AVL Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Imprime as chaves da AVL Tree em ordem
    cout << "Chaves na AVL Tree em ordem: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
```

Neste exemplo, a estrutura `Node` representa um nó na AVL Tree. Cada nó armazena uma chave, ponteiros para os filhos esquerdo e direito, e a altura do nó. A função `insert` insere uma chave na AVL Tree, mantendo-a balanceada através de rotações simples e duplas quando necessário.

## RB Tree

Uma Red-Black Tree (Árvore Rubro-Negra) é uma árvore de busca binária auto balanceada que garante que a altura da árvore permaneça logarítmica em relação ao número de nós, mesmo após operações de inserção e remoção. Essa estrutura é amplamente usada em implementações de mapas ordenados e conjuntos em linguagens de programação.

Aqui está um exemplo de implementação básica de uma Red-Black Tree em C++:

```cpp
#include <iostream>

using namespace std;

// Definição dos possíveis tipos de cores para os nós
enum Color { RED, BLACK };

// Definição da estrutura do nó da Red-Black Tree
struct Node {
    int key;
    Color color;
    Node *left, *right, *parent;

    // Construtor para criar um novo nó com uma chave específica e cor vermelha
    Node(int k) : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Função auxiliar para realizar uma rotação à esquerda
void rotateLeft(Node*& root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

// Função auxiliar para realizar uma rotação à direita
void rotateRight(Node*& root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != nullptr)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

// Função auxiliar para ajustar a propriedade de cores e a estrutura da árvore após a inserção
void fixInsert(Node*& root, Node* z) {
    while (z != root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(root, z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(root, z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

// Função para inserir uma chave na Red-Black Tree
Node* insert(Node*& root, int key) {
    Node* z = new Node(key);
    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == nullptr)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    fixInsert(root, z);
    return root;
}

// Função auxiliar para imprimir as chaves da Red-Black Tree em ordem
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    // Inicializa uma Red-Black Tree vazia
    Node* root = nullptr;

    // Insere algumas chaves na Red-Black Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Imprime as chaves da Red-Black Tree em ordem
    cout << "Chaves na Red-Black Tree em ordem: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
```

Neste exemplo, a estrutura `Node` representa um nó na Red-Black Tree. Cada nó possui uma chave, uma cor (vermelha ou preta), e ponteiros para os filhos esquerdo e direito e para o pai. As funções `rotateLeft` e `rotateRight` realizam rotações simples em torno dos nós. A função `fixInsert` ajusta as propriedades da árvore após a inserção de um novo nó, mantendo a estrutura balanceada e garantindo que as propriedades da Red-Black Tree sejam preservadas.
