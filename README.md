# Algoritmo de K Vizinhos em C - Classificação com ML

## Sobre o projeto

Este código foi desenvolvido para fins de estudo sobre *Inteligência Artificial* e técnicas de *Aprendizado de Máquina* dentro da comunidade estudantil [HackoonSpace](https://hackoonspace.com).

## Sobre o algoritmo

O algoritmo aqui implementado é chamado de **K Vizinhos mais próximos** (KNN, em inglês). É uma das técnicas mais simples e utilizadas na classificação de amostras com Machine Learning, bem como em sistemas de recomendação.

Para melhor compreensão de como o algoritmo funciona, é recomendado visitar os links presentes na seção de *referências* deste README.

O código-fonte do projeto foi escrito na linguagem C, e algumas adaptações foram feitas para melhor didática. É recomendado ler os comentários fornecidos no próprio código para compreender quais modificações são necessárias para utilizar o projeto em uma aplicação real.

Em geral, este KNN utiliza **dois atributos** diferentes (X e Y) de uma nova amostra para realizar uma **classificação binária** (classes 0 e 1) baseada em 10 dados já classificados gerados pelo próprio algoritmo. O cálculo da distância entre os dados é feito utilizando **distância euclidiana**.

## Compilação e execução

Para compilar o código, utilize o comando (com GCC) ou compile com o seu compilador de C de preferência:

```c
    gcc kVizinhos.c -o kVizinhos
```

Posteriormente, execute o executável gerado no diretório da forma apropriada ao seu sistema operacional.

Ao executar, o programa irá pedir para que você informe:
- *Um valor para K (use de preferência valores impares)*
- *Valor da amostra no eixo X*
- *Valor da amostra no eixo Y*

É importante ressaltar que, para este algoritmo, K não pode ser maior do que 10 apenas porquê o tamanho da base de dados usada para a classificação é 10. Em uma aplicação real, com uma base bem maior, não haveria este tipo de limitação.

Após informar os dados de entrada, o algoritmo irá mostrar duas listas:
- Lista total de vizinhos
- Lista dos K vizinhos mais próximos da amostra

Para ambas, ele irá mostrar os valores dos atributos em X e Y e as respectivas classes de cada vizinho. Por fim, ele irá realizar a classificação utilizando os dados da segunda lista.

## Referências e materiais

Para o desenvolvimento deste código, foram usados os seguintes materiais de apoio:

- [Algoritmos de Aprendizagem de Máquina: qual deles escolher?](https://medium.com/machina-sapiens/algoritmos-de-aprendizagem-de-m%C3%A1quina-qual-deles-escolher-67040ad68737)
- [KNN (K-Nearest Neighbors) #1](https://medium.com/brasil-ai/knn-k-nearest-neighbors-1-e140c82e9c4e)
- [Machine Learning Basics with the K-Nearest Neighbors Algorithm](https://towardsdatascience.com/machine-learning-basics-with-the-k-nearest-neighbors-algorithm-6a6e71d01761)
- [K-Nearest Neighbours](https://www.geeksforgeeks.org/k-nearest-neighbours/)
- [Slides sobre IA do HackoonSpace](https://drive.google.com/file/d/1QJQAkjh4uKjqAIsGCeuzoDYqo9UPLuPE/view?usp=sharing)