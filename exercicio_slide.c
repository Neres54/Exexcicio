/*Escreva uma função que recebe sete parâmetros:
– o inteiro n indicando a quantidade de participantes do concurso
– o ponteiro inscr para o vetor de inteiros que contém as
inscrições desses participantes
– o ponteiro t1 para o vetor de reais que contém a nota de cada
participante no primeiro teste
– o inteiro p1 que indica o peso dessa nota na média ponderada
– o ponteiro t2 para o vetor de reais que contém a nota de cada
participante no segundo teste
– o inteiro p2 que indica o peso dessa nota na média ponderada
– um ponteiro para a variável inteira tam
*/
#include <stdio.h>
#include <stdlib.h>

int *premiados(int n, int *inscr, float *t1, int p1, float *t2, int p2, int *tam) {
    float media, maior_media = 0;
    int i, numPremiados = 0;

    for (i = 0; i < n; i++) {
        media = (t1[i] * p1 + t2[i] * p2) / (p1 + p2);
        if (media > maior_media) {
            maior_media = media;
        }
    }

    for (i = 0; i < n; i++) {
        media = (t1[i] * p1 + t2[i] * p2) / (p1 + p2);
        if (media == maior_media) {
            numPremiados++;
        }
    }

    int *premiados = (int *)malloc(numPremiados * sizeof(int));
    if (premiados == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }

    int j = 0;
    for (i = 0; i < n; i++) {
        media = (t1[i] * p1 + t2[i] * p2) / (p1 + p2);
        if (media == maior_media) {
            premiados[j] = inscr[i];
            j++;
        }
    }

    *tam = numPremiados;

    return premiados;
}

int main() {
    int n;
    printf("Digite o número de participantes: ");
    scanf("%d", &n);

    int *inscricoes = (int *)malloc(n * sizeof(int)); 
    if (inscricoes == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }

    float *notas1 = (float *)malloc(n * sizeof(float)); 
    if (notas1 == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }

    float *notas2 = (float *)malloc(n * sizeof(float)); 
    if (notas2 == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }

    int i;
    
    for (i = 0; i < n; i++) {
        printf("Digite a inscrição do participante %d: ", i + 1);
        scanf("%d", &inscricoes[i]);
        printf("Digite a nota do primeiro teste do participante %d: ", i + 1);
        scanf("%f", &notas1[i]);
        printf("Digite a nota do segundo teste do participante %d: ", i + 1);
        scanf("%f", &notas2[i]);
    }

    int peso1 = 3; 
    int peso2 = 2; 
    int tam;

   
    int *premiados_vec = premiados(n, inscricoes, notas1, peso1, notas2, peso2, &tam);

    printf("Participantes premiados: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", premiados_vec[i]);
    }
    printf("\n");

    free(inscricoes);
    free(notas1);
    free(notas2);
    free(premiados_vec);

    return 0;
}
