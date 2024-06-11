# Hash

Claro! Vamos falar sobre hashes em estrutura de dados.

**O que são Hashes?**
Um hash é uma função que mapeia dados de tamanho variável para dados de tamanho fixo. É como uma impressão digital de um conjunto de dados. Essa função é projetada para ser rápida de calcular e geralmente é irreversível, o que significa que é difícil (idealmente impossível) regenerar os dados originais a partir do hash.

**Para que servem?**
Hashes são amplamente usados em estrutura de dados para indexação eficiente, pesquisa e verificação de integridade de dados. Alguns dos principais usos incluem:

1. **Tabelas de Hash:** São estruturas de dados que usam hashes para mapear chaves para valores, permitindo acesso rápido aos dados.
2. **Criptografia:** Hashes são usados em criptografia para verificar a integridade dos dados e para armazenar senhas de forma segura.
3. **Detecção de Duplicatas:** Hashes podem ser usados para detectar duplicatas em grandes conjuntos de dados de forma eficiente.
4. **Verificação de Integridade:** Ao calcular o hash de um conjunto de dados, você pode comparar esse hash com um valor conhecido para verificar se os dados foram alterados.

**Como funcionam?**
Quando você aplica uma função de hash a um conjunto de dados, ela produz um valor hash único que representa esses dados. Idealmente, diferentes conjuntos de dados devem produzir valores hash completamente diferentes. No entanto, devido à limitação do tamanho fixo do hash, pode haver colisões, onde dois conjuntos de dados diferentes produzem o mesmo valor hash. Para minimizar as colisões, são usadas técnicas como funções de hash bem projetadas e tabelas de hash de tamanho adequado.

Em resumo, hashes são ferramentas poderosas em estrutura de dados que permitem indexação rápida, verificação de integridade e outras operações importantes em conjuntos de dados.

## Hashing

Função simples de hashing que recebe uma string como entrada e retorna um valor hash baseado nos caracteres dessa string.

```c
#include <stdio.h>
#include <string.h>

// Tamanho máximo da tabela de hash
#define TABLE_SIZE 100

// Estrutura para armazenar elementos na tabela de hash
struct HashElement {
    char key[50];
    int value;
};

// Função de hashing simples
int hashFunction(const char* key) {
    int hash = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

// Função para inserir um elemento na tabela de hash
void insert(struct HashElement table[], const char* key, int value) {
    int index = hashFunction(key);
    while (table[index].value != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    strcpy(table[index].key, key);
    table[index].value = value;
}

// Função para buscar um elemento na tabela de hash
int search(struct HashElement table[], const char* key) {
    int index = hashFunction(key);
    while (strcmp(table[index].key, key) != 0) {
        index = (index + 1) % TABLE_SIZE;
        if (table[index].value == -1) {
            return -1; // Elemento não encontrado
        }
    }
    return table[index].value;
}

int main() {
    // Inicializa a tabela de hash com valores padrão
    struct HashElement hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        strcpy(hashTable[i].key, "");
        hashTable[i].value = -1; // Valor -1 indica que a célula está vazia
    }

    // Insere alguns elementos na tabela de hash
    insert(hashTable, "banana", 10);
    insert(hashTable, "apple", 20);
    insert(hashTable, "orange", 30);

    // Busca por elementos na tabela de hash
    printf("O valor para a chave 'banana' é: %d\n", search(hashTable, "banana"));
    printf("O valor para a chave 'apple' é: %d\n", search(hashTable, "apple"));
    printf("O valor para a chave 'orange' é: %d\n", search(hashTable, "orange"));
    printf("O valor para a chave 'grape' é: %d\n", search(hashTable, "grape")); // Chave não existente

    return 0;
}
```

Este é um exemplo muito básico e não ideal de um algoritmo de hashing. Ele usa uma função de hash simples que soma os valores ASCII dos caracteres na chave e retorna um valor hash mapeado para o intervalo [0, TABLE_SIZE - 1]. Em seguida, ele usa uma técnica de tratamento de colisões chamada sondagem linear para lidar com colisões simplesmente pulando para a próxima posição na tabela de hash até encontrar uma posição vazia.

## Tabela Hash

Nesse exemplo, vamos usar uma técnica simples de resolução de colisões chamada encadeamento, onde cada entrada na tabela de hash contém uma lista encadeada de elementos.

```cpp
#include <iostream>
#include <list>
#include <string>

// Definição de uma estrutura para armazenar elementos na tabela de hash
struct HashElement {
    std::string key;
    int value;
};

// Definição da classe HashTable
class HashTable {
private:
    static const int TABLE_SIZE = 100; // Tamanho da tabela de hash
    std::list<HashElement> table[TABLE_SIZE]; // Tabela de hash implementada como um array de listas encadeadas

    // Função de hashing simples que retorna um índice baseado na chave
    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % TABLE_SIZE;
    }

public:
    // Função para inserir um elemento na tabela de hash
    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        HashElement newElement = {key, value};
        table[index].push_back(newElement);
    }

    // Função para buscar um elemento na tabela de hash
    int search(const std::string& key) {
        int index = hashFunction(key);
        for (const auto& element : table[index]) {
            if (element.key == key) {
                return element.value;
            }
        }
        return -1; // Retorna -1 se a chave não for encontrada
    }
};

int main() {
    HashTable hashTable;

    // Insere alguns elementos na tabela de hash
    hashTable.insert("banana", 10);
    hashTable.insert("apple", 20);
    hashTable.insert("orange", 30);

    // Busca por elementos na tabela de hash
    std::cout << "O valor para a chave 'banana' é: " << hashTable.search("banana") << std::endl;
    std::cout << "O valor para a chave 'apple' é: " << hashTable.search("apple") << std::endl;
    std::cout << "O valor para a chave 'orange' é: " << hashTable.search("orange") << std::endl;
    std::cout << "O valor para a chave 'grape' é: " << hashTable.search("grape") << std::endl; // Chave não existente

    return 0;
}
```

Neste exemplo, a classe `HashTable` contém um array de listas encadeadas (`std::list`) chamada `table`, onde cada entrada no array é uma lista de elementos. A função `hashFunction` é usada para calcular o índice no array com base na chave.

A função `insert` insere um novo elemento na lista correspondente ao índice calculado.

A função `search` procura um elemento na lista correspondente ao índice calculado. Se a chave é encontrada, o valor associado a essa chave é retornado; caso contrário, é retornado -1.

## Hash Mapping

Um hash mapping, ou mapeamento por hash, é uma estrutura de dados que mapeia chaves para valores usando uma função de hash. Em C/C++, podemos implementar um hash mapping usando uma tabela de hash, onde cada entrada da tabela contém uma chave e seu respectivo valor. Aqui está um exemplo básico de como implementar um hash mapping em C++:

```cpp
#include <iostream>
#include <string>

// Definição de uma estrutura para armazenar elementos na tabela de hash
struct HashElement {
    std::string key;
    int value;
};

// Definição da classe HashMap
class HashMap {
private:
    static const int TABLE_SIZE = 100; // Tamanho da tabela de hash
    HashElement* table[TABLE_SIZE]; // Tabela de hash implementada como um array de ponteiros

    // Função de hashing simples que retorna um índice baseado na chave
    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % TABLE_SIZE;
    }

public:
    // Construtor: inicializa a tabela de hash
    HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    // Destrutor: libera a memória alocada para os elementos da tabela de hash
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
    }

    // Função para inserir um elemento na tabela de hash
    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        // Cria um novo elemento e insere na tabela
        HashElement* newElement = new HashElement {key, value};
        table[index] = newElement;
    }

    // Função para buscar um elemento na tabela de hash
    int search(const std::string& key) {
        int index = hashFunction(key);
        // Verifica se o elemento está na posição index da tabela
        if (table[index] != nullptr && table[index]->key == key) {
            return table[index]->value;
        } else {
            return -1; // Retorna -1 se a chave não for encontrada
        }
    }
};

int main() {
    HashMap hashMap;

    // Insere alguns elementos no hash mapping
    hashMap.insert("banana", 10);
    hashMap.insert("apple", 20);
    hashMap.insert("orange", 30);

    // Busca por elementos no hash mapping
    std::cout << "O valor para a chave 'banana' é: " << hashMap.search("banana") << std::endl;
    std::cout << "O valor para a chave 'apple' é: " << hashMap.search("apple") << std::endl;
    std::cout << "O valor para a chave 'orange' é: " << hashMap.search("orange") << std::endl;
    std::cout << "O valor para a chave 'grape' é: " << hashMap.search("grape") << std::endl; // Chave não existente

    return 0;
}
```

Neste exemplo, a classe `HashMap` contém um array de ponteiros chamado `table`, onde cada entrada na tabela é um ponteiro para um elemento da estrutura `HashElement`, que armazena uma chave e um valor.

A função `hashFunction` é usada para calcular o índice na tabela com base na chave. A função `insert` insere um novo elemento na posição correspondente na tabela de hash, enquanto a função `search` procura por um elemento na posição correspondente na tabela e retorna o valor associado à chave, se encontrado.
