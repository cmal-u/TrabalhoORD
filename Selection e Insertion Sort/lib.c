#include <stdio.h>
#include "lib.h"


/* ordena um vetor */
void selectionSort(int *A, int tam)
{
    int m, aux;
    for(int i = 0; i < tam; i++) {
        m = menorIndex(A, tam, i);
        aux = A[i];
        A[i] = A[m];
        A[m] = aux;
    }
}

/*
*   retorna o indice do menor valor do array a partir da posicao
*   passada nos parametros
*/
int menorIndex(int A[], int tam, int s)
{
    int index = s;
    for(int i = ++s; i < tam; i++) {
        if(A[i] < A[index])
            index = i;
    }
    return index;
}

/* ordena um vetor */
void insertionSort(int *A, int tam)
{
    int elemento, j;
    for(int i = 1; i < tam; i++) {
        elemento = A[i];
        j = i;
        while(j > 0 && A[j-1] > elemento) {
            A[j] = A[j-1];
            j -= 1;
        }
        A[j] = elemento;
    }
}


/*
*   confirma se o arquivo passado pelos parametros foi
*   aberto com sucesso.
*   retorna uma msg de erro e -1 se nao foi possivel
*   realizar a instrucao, caso contrario, retorna 0
*/
int tentarAbrir(FILE *a, int nArq) {
    if(a == NULL) {
        printf("\n>>>Nao foi possivel abrir arquivo %d\n", nArq);
        return -1;
    }

    return 0;
}

/*
*   Faz a ordenacao dos numeros do arquivo passado por parametro
*   atraves do insertion sort e cria um novo arquivo ordenado.
*/
void processarArqInsertion(FILE *a)
{
    int cont = 0, tamanho = 0;
    char linha[100], *primeiraLinha;

    fgets(linha, sizeof linha, a);
    primeiraLinha = strtok(linha, " ");

    tamanho = atoi(primeiraLinha);
    int vetor[tamanho];

    while(!feof(a)) {
        fscanf(a, "%d", &vetor[cont++]);
        ///printf("%d\n", vetor[cont++]);
    }
    fclose(a);

    insertionSort(vetor, tamanho);

    FILE* novoArq = fopen("insertionSort.txt","w+");
    criarArquivo(novoArq, tamanho, vetor);

}

/*
*   Faz a ordenacao dos numeros do arquivo passado por parametro
*   atraves do selection sort e cria um novo arquivo ordenado.
*/
void processarArqSelection(FILE *a)
{
    int cont = 0, tamanho = 0;
    char linha[100], *primeiraLinha;

    fgets(linha, sizeof linha, a);
    primeiraLinha = strtok(linha, " ");

    tamanho = atoi(primeiraLinha);
    int vetor[tamanho];

    while(!feof(a)) {
        fscanf(a, "%d", &vetor[cont++]);
        //printf("%d\n", vetor[cont++]);
    }

    fclose(a);

    selectionSort(vetor, tamanho);

    FILE* novoArq = fopen("selectionSort.txt","w+");
    criarArquivo(novoArq, tamanho, vetor);
}


/*
*   Cria novo arquivo ordenado.
*/
void criarArquivo(FILE *a, int tamanho, int v[])
{
    if (a != NULL) {
        for(int i = 0; i < tamanho; i++) {
            fprintf(a,"%d\n", v[i]);
        }
        fclose(a);
    }
}
