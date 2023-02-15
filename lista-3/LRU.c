#include <stdio.h>
#include <stdlib.h>

// typedef struct Item{
//     int qnt;
//     int number;
// } item;


int busca(int *quadros, int x, int Q, int N){
    for(int i=0;i<Q;i++){
        if(quadros[i]==x) return quadros[i];
    }
    return -1;
}

void imprime(int *quadros, int Q){
    for(int i=0;i<Q;i++){
        printf("%d ", quadros[i]);
    }
    printf("\n");
}

int least(int *quadros, int *pages, int Q){
    int index = -1;
    int least = 100000;
    for(int i = 0; i < Q ;i++){
        if(pages[quadros[i]]<least){
            least = pages[quadros[i]];
            index = i;
        }
    }
    return index;
}
int lru(int *quadros, int *vetor, int *pages, int Q, int N){
    int pageFaults = 0;
    int index = 0;
    int numero = 1;
    for(int i=0;i<N;i++){
        int achou = busca(quadros, vetor[i], index, N);
        if(achou!=-1){
            pages[vetor[i]]=numero++;
        }
        else{
            pageFaults++;
            if(index<Q){
                quadros[index++] = vetor[i];
                pages[vetor[i]]=numero++;
            }
            else{
                int j = least(quadros, pages, Q);
                quadros[j] = vetor[i];
                pages[vetor[i]] = numero++;
            }
        }
    }
    return pageFaults;
}

int main(){
    int Q, N, x, y;
    scanf("%d", &Q);
    int *pages = malloc(sizeof(int)*1000000);
    int *quadros = malloc(sizeof(int)*Q);
    scanf("%d", &N);
    int *vetor = malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d", &vetor[i]);
        pages[vetor[i]] = 0;
    }

    printf("%d\n", lru(quadros, vetor,pages, Q, N));
    return 0; 
}