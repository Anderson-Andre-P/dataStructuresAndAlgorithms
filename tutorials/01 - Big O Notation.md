# DSA - Data Structures and Algorithms

## Big O Notation

É uma medida abstrata da ordem de grandeza/crescimento de um algoritmo conforme os dados aumentam. São duas grandezas avaliadas: tempo de execução e espaço de memória alocada.

Para avaliar o Big O Notation, é utilizado uma área da matemática chamada "Análise Assintótica". Essa área é responsável por cuidar de números grandes.

Na prática, para avaliar com a análise assintótica, as constantes e os expoentes de menor magnitude são ignorados para simplificar a comparação de funções.

## Como Determinar a Complexidade de um Algoritmo

Abaixo, está listado algumas diretrizes para auxiliar a encontrar a complexidade linear.

1.  **Entenda a estrutura do algoritmo:** Primeiro é importante entender a estrutura do algoritmo, incluindo: loops, chamadas de funções e operações realizadas.
2.  **Identificar blocos de código:** Divida o algoritmo em blocos menores e analise cada bloco separadamente. Cada bloco pode ter sua própria complexidade, e o comportamento combinado dos blocos determinará a complexidade total do algoritmo.
3.  **Calcular a complexidade de cada bloco:** Para cada bloco de código, calcule a complexidade com base nos seguintes componentes principais:

    - **Loops simples:** Um loop vai de 1 a n tem complexidade constante. Complexidade: $\theta(n)$.

    ```c
    for (int i = 0; i <= n; i++) {
         // Código constante
    }
    ```

    - **Loops aninhados:** Cada loop aninhado multiplica a complexidade. Complexidade: $\theta(n \cdot n) = \theta(n^2)$.

    ```c
    for (int i = 0; i <= n; i++) {
         for (int j = 1; j <= n; j++) {
             // Código constante
         }
    }
    ```

    - **Loops que crescem exponencialmente:** $\theta(\log n)$.

    ```c
    for (int i = 1; i <= n; i *= 2) {
         // Código constante
    }
    ```

    - **Loops quadráticos ou polinomiais:** Os loops quadráticos, cúbicos e outros polinomiais ocorrem quando há múltiplos loops aninhados, onde cada loop depende do tamanho do problema $n$.
      - Loop quadrático: Complexidade: $\theta(n \cdot n) = \theta(n^2)$.
      - Loop cúbico: Complexidade: $\theta(n \cdot n \cdot n) = \theta(n^3)$.

    ```c
    for (int i = 0; i <= n; i++) {
         for (int j = 1; j <= n; j++) {
             // Código constante
         }
    }
    ```

    ```c
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                // Código constante
            }
        }
    }
    ```

    - **Loops sublineares:** Ocorrem quando o número de iterações de um loop é uma função sub-linear do tamanho do problema. Complexidade: $\theta(\sqrt{n})$.

    ```c
    for (int i = 1; i <= sqrt(n); i++) {
        // Código constante
    }
    ```

    - **Loops combinatórios:** Ocorrem em situações onde há uma combinação de iterações que resultam em um grande número de casos. Complexidade: $\theta(2^n \cdot n)$.

    ```c
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                // Código constante
            }
        }
    }
    ```

    - **Loops exponenciais:** Ocorrem em algoritmos onde o número de iterações cresce exponencialmente com o tamanho do problema. Complexidade: $\theta(2^n)$.

    ```c
    void rec(int n) {
        if (n <= 1) return n;
        rec (n - 1);
        rec (n - 1);
    }
    ```

    - **Loops com complexidade amortizada:** Às vezes, a complexidade de um loop pode ser analisada usando a análise amortizada, onde o custo de uma operação é avaliado ao longo de uma sequência de operações. Complexidade amortizada:
      - $\theta(1)$ por inserção.
      - $\theta(n)$ no total.

    ```c
    vector <int>v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }
    ```

    - **Loops com iterações dependentes:** Em alguns casos, a quantidade de iterações de um loop depende de operações internas ou de variáveis externas. Aqui a complexidade dependerá da função $f(i)$. Se $f(i)$ for linear, a complexidade pode ser $\theta(n^2)$, se for logarítimica, a complexidade pode ser $\theta(n \log n)$, e assim por diante.

    ```c
    for (int i = 1; i <= n; i++) {
        for (int j =1; j <= f(i); j++) {
            // Código constante
        }
    }
    ```

## Resumo dos Tipos de Complexidade

- Loops simples: $\theta(n)$.
- Loops aninhados: $\theta(n^2)$.
- Loops que crescem exponencialmente: $\theta(\log n)$.
- Quadráticos/Cúbicos/Polinomiais: $\theta(n^2)$, $\theta(n^3)$, $\theta(n^n)$...
- Sub-lineares: $\theta(\sqrt{n})$.
- Logarítimicos: $\theta(n \cdot \log n)$.
- Combinatórios: $\theta(2^n \cdot n)$.
- Exponenciais: $\theta(2^n)$.
- Amortizados: $\theta(1)$ por operação em média.
- Dependentes: Varia conforme a função interna.

<!-- $\theta(n)$
$\theta(n^2)$
$\theta(n \log n)$
$\log_{2}n$ -->
