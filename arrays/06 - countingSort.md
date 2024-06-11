# Counting Sort

O algoritmo Counting Sort classifica um array contando o número de vezes que cada valor ocorre.

Counting Sort não compara valores como os algoritmos de classificação anteriores que vimos e só funciona em números inteiros não negativos.

Além disso, Counting Sort é rápido quando o intervalo de valores possíveis $k$ é menor que o número de valores $n$.

### Como funciona

1. Crie uma novo array para contar quantos valores diferentes existem.
2. Percorra o array que precisa ser classificada.
3. Para cada valor, conte-o aumentando o array de contagem no índice correspondente.
4. Após contar os valores, percorra o array de contagem para criar o array classificada.
5. Para cada contagem no array de contagem, crie o número correto de elementos, com valores que correspondam ao índice do array de contagem.

## Condições para classificação de contagem

Estas são as razões pelas quais se diz que Counting Sort funciona apenas para um intervalo limitado de valores inteiros não negativos:

- **Valores inteiros:** A classificação por contagem depende da contagem de ocorrências de valores distintos, portanto, eles devem ser inteiros. Com números inteiros, cada um se ajusta a um índice (para valores não negativos), e há um número limitado de valores diferentes, de modo que o número de valores diferentes possíveis $k$ não é muito grande comparado ao número de valores $n$.
- **Valores não negativos:** A classificação por contagem geralmente é implementada criando um array para contagem. Quando o algoritmo passa pelos valores a serem classificados, o valor x é contado aumentando o valor do array de contagem no índice x. Se tentássemos classificar valores negativos, teríamos problemas ao classificar o valor -3, porque o índice -3 estaria fora do array de contagem.
- **Intervalo limitado de valores:** Se o número de possíveis valores diferentes a serem classificados $k$ for maior que o número de valores a serem classificados $n$, o array de contagem necessária para a classificação será maior que a original array que temos que precisa ser classificado e o algoritmo se torna ineficaz.

## Execução manual

Antes de implementar o algoritmo Counting Sort em uma linguagem de programação, vamos executar manualmente um pequeno array, só para ter uma ideia.

**Etapa 1:** começamos com um array não classificado.

[2, 3, 0, 2, 3, 2]

**Etapa 2:** criamos outro array para contar quantos existem de cada valor. o array possui 4 elementos, para armazenar valores de 0 a 3.

minhaArray = [2, 3, 0, 2, 3, 2]

contagemArray = [0, 0, 0, 0]

**Etapa 3:** agora vamos começar a contar. O primeiro elemento é 2, então devemos incrementar o elemento do array de contagem no índice 2.

minhaArray = [`2`,3, 0, 2, 3, 2]

contagemArray = [0, 0, `1`,0]

**Etapa 4:** Depois de contar um valor, podemos removê-lo e contar o próximo valor, que é 3.

minhaArray = [`3`,0, 2, 3, 2]

contagemArray = [0, 0, 1, `1`]

**Etapa 5:** O próximo valor que contamos é 0, então incrementamos o índice 0 no array de contagem.

minhaArray = [`0`,2, 3, 2]

contagemArray = [`1`,0, 1, 1]

**Etapa 6:** continuamos assim até que todos os valores sejam contados.

minhaArray = []

contagemArray = [`1`, `0`, `3`, `2`]

**Etapa 7:** agora vamos recriar os elementos do array inicial, e faremos isso de forma que os elementos sejam ordenados do menor para o maior.

O primeiro elemento no array de contagem nos diz que temos 1 elemento com valor 0. Portanto, colocamos 1 elemento com valor 0 no array e diminuímos o elemento no índice 0 no array de contagem com 1.

minhaArray = [`0`]

contagemArray = [`0`,0, 3, 2]

**Etapa 8:** no array de contagem vemos que não precisamos criar nenhum elemento com valor 1.

minhaArray = [0]

contagemArray = [0, `0`,3, 2]

**Etapa 9:** colocamos 3 elementos com valor 2 no final do array. E à medida que criamos esses elementos também diminuímos o array de contagem no índice 2.

minhaArray = [0, `2`, `2`, `2`]

contagemArray = [0, 0, `0`,2]

**Etapa 10:** por fim devemos adicionar 2 elementos com valor 3 no final do array.

minhaArray = [0, 2, 2, 2, `3`, `3`]

contagemArray = [0, 0, 0, `0`]

Finalmente! o array está classificada.

## Execução manual: o que aconteceu?

Antes de implementarmos o algoritmo em uma linguagem de programação, precisamos analisar com mais detalhes o que aconteceu acima.

<!-- <center>
    <img src="../images/arrays/img_runtime_n^2.png" alt="Runtime Insertion Sort">
</center> -->
