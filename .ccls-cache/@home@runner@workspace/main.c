#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//============================================
void printfVet(int *V  , int N){
    int i;
    for(i = 0; i < N; i++)
        printf("%2d ",V[i]);
    printf("\n");
}

void printfLinha(){
    printf("----------------------------------------------\n");
}
//============================================

int particiona(int *V, int inicio, int final, int *comparacoes, int *movimentacoes ){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while(esq < dir){
        (*comparacoes)++;

        while(esq <= final && V[esq] <= pivo){
            (*comparacoes)++;
            esq++;
        }
        while(dir >= 0 && V[dir] > pivo){
            (*comparacoes)++;
            dir--;
        }
        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
            (*movimentacoes) += 2;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    (*movimentacoes) += 2 ;
    printf("---------------\n");
    return dir;
}

void quickSort(int *V, int inicio, int fim, int *comparacoes, int *movimentacoes) {
    int pivo;
    if(fim > inicio){
        (*comparacoes)++;
        pivo = particiona(V, inicio, fim, comparacoes, movimentacoes);
        quickSort(V, inicio, pivo-1, comparacoes, movimentacoes);
        quickSort(V, pivo+1, fim, comparacoes, movimentacoes);
    }
}

//============================================

void salvarResultados(int *vet, int N, int comparacoes, int movimentacoes) {
    FILE *arquivo = fopen("resultados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo resultados.txt!\n");
        return;
    }
    
    fprintf(arquivo, "=== RESULTADOS DA ORDENAÇÃO QUICKSORT ===\n\n");
    
    fprintf(arquivo, "Vetor ordenado: ");
    for(int i = 0; i < N; i++){
        fprintf(arquivo, "%2d ", vet[i]);
    }
    fprintf(arquivo, "\n\n");
    
    fprintf(arquivo, "Estatísticas da ordenação:\n");
    fprintf(arquivo, "- Número de comparações: %d\n", comparacoes);
    fprintf(arquivo, "- Número de movimentações: %d\n", movimentacoes);
    fprintf(arquivo, "- Tamanho do vetor: %d elementos\n", N);
    
    fclose(arquivo);
    printf("Resultados salvos em 'resultados.txt'\n");
}

int main(){
    int vet[6];
    int N = 6, comparacoes = 0, movimentacoes = 0;
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        vet[i] = rand() % 100;
    }
    
    printf("Sem ordenar:\n");
    printfVet(vet,N);
    printfLinha();

    quickSort(vet,0,N-1, &comparacoes, &movimentacoes);//OK
    printf("Ordenado:\n");
    printfVet(vet,N);

    printf("Número de comparações: %d\n", comparacoes);
    printf("Número de movimentações: %d\n", movimentacoes);

    // Salvar resultados no arquivo
    salvarResultados(vet, N, comparacoes, movimentacoes);

    system("pause");
    return 0;
}