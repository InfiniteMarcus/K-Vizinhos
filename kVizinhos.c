#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	Struct representando uma amostra qualquer
	- classe => valor 0 ou 1, que representa a qual classe a amostra pertence
	- x, y => coordenadas em x e y, representando os dados da amostra
	- distancia => distancia da amostra em relação ao novo dado a ser classificado
		* Por padrão, é iniciada com -1 para representar que não há distância calculada ainda
*/
typedef struct Amostra {
	int classe;
	int x, y;
	int distancia;
} Amostra;

// Função para preencher base de dados com amostras """aleatórias"""
// AVISO: Isto é uma gambiarra. Na vida real, você abriria um arquivo com os dados verdadeiros já classificados
Amostra * preencheVizinhos(int numVizinhos) {
	
	Amostra * vizinhos = (Amostra *) malloc(sizeof(Amostra) * numVizinhos);
	
	for(int i = 0; i < numVizinhos; i++){
		vizinhos[i].classe = (i < 5 ? 0 : 1);
		vizinhos[i].x = i + 1;
		vizinhos[i].y = i * 2;
		vizinhos[i].distancia = -1;	
	}
	
	return vizinhos;
}

// Função para printar os dados/vizinhos já classificados do conjunto de dados
void printaVizinhos(Amostra * vizinhos, int numVizinhos) {
	printf("PRINTANDO LISTA DE %d VIZINHOS:\n", numVizinhos);
	for(int i = 0; i < numVizinhos; i++)
		printf("> Vizinho %d: x = %d, y = %d, classe = %d\n", i+1, vizinhos[i].x, vizinhos[i].y, vizinhos[i].classe);
}

// Função de comparação de distancias, para ser usada na função de ordenação já embutida do C
int comparaAmostras(const void * a, const void * b) {
	
	Amostra * temp1 = (Amostra *) a;
	Amostra * temp2 = (Amostra *) b;
	
	return  (temp1->distancia > temp2->distancia);
}

// Calculo da distancia euclidiana de duas amostras
// Basicamente, ele faz a raiz quadrada da soma das diferenças ao quadrado dos eixos das amostras
int distanciaEuclidiana(Amostra vizinho, Amostra p) {
	return sqrt((vizinho.x - p.x) * (vizinho.x - p.x) + (vizinho.y - p.y) * (vizinho.y - p.y));
}

/*
	Função que calcula as distancias da nova amostra p em relação a base de dados,
	ordenando os vizinhos em relação a distancia da amostra e escolhendo a classe
	a partir K vizinhos mais próximos

	OBSERVAÇÃO: Este algoritmo está considerando a existência de apenas duas classes (0 e 1)
*/
int classifiacao(Amostra vizinhos[], Amostra p, int k, int numVizinhos) {
	
    for (int i = 0; i < numVizinhos; i++)
        vizinhos[i].distancia = distanciaEuclidiana(vizinhos[i], p);
        
    qsort(vizinhos, numVizinhos, sizeof(Amostra), comparaAmostras);
 
    int freq1 = 0;
    int freq2 = 0;
    for (int i = 0; i < k; i++) {
        if (vizinhos[i].classe == 0)
            freq1++;
        else if (vizinhos[i].classe == 1)
            freq2++;
    }
 
 


    return (freq1 > freq2 ? 0 : 1);
}

int main() {
	
	int numVizinhos = 10;
	int k = 0;

	printf("Algoritmo de classificacao por K vizinhos mais proximos, considerando duas classes (0 e 1)\n\n");
	printf("Indique o valor de K (quantos vizinhos mais proximos serao usados para classificar a amostra): \n");
	scanf("%d", &k);
	
	if(k > numVizinhos || k < 1){
		printf("Valor de K maior/menor do que o limite de dados");
		return 0;
	}

	Amostra p;
	p.classe = -1;
	p.distancia = 0;
	
	printf("Valor no eixo x da amostra: \n");
	scanf("%d", &p.x);
	
	printf("Valor no eixo y da amostra: \n");
	scanf("%d", &p.y);
	
	Amostra * vizinhos = preencheVizinhos(numVizinhos);
	printaVizinhos(vizinhos, numVizinhos);
	
	int classe = classifiacao(vizinhos, p, k, numVizinhos);

	printf("A classe do dado p eh: %d\n", classe);
	
	free(vizinhos);

	return 0;
}
