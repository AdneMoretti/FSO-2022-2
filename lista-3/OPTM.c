#include <stdio.h>
#include <stdlib.h>

int busca(int *quadros, int x, int Q, int N){
    for(int i=0;i<Q;i++){
        if(quadros[i]==x) return 1;
    }
    return 0;
}

int predict(int *vetor, int *quadros, int Q, int N, int index){
    int posicao = -1, far = index;
    for(int i=0;i<Q;i++){
        int j;
        for(j=index;j<N;j++){
            if(quadros[i] == vetor[j]){
                if(j>far){ 
                    far=j;
                    posicao=i;
                }
                break;
            }
        }
        if(j==N) return i;
    }
    if(posicao==-1) return 0;
    else return posicao;
}
void imprime(int *quadros, int Q){
    for(int i=0;i<Q;i++){
        printf("%d ", quadros[i]);
    }
    printf("\n");
}
int otm(int *quadros, int *vetor, int Q, int N){
    int pageFaults = 0;
    int index = 0;
    for(int i=0;i<N;i++){
        if(!busca(quadros, vetor[i], index, N)){
            pageFaults++;
            if(index<Q){
                quadros[index++] = vetor[i];
            }
            else{
                int j = predict(vetor, quadros, Q, N, i+1);
                quadros[j] = vetor[i];
            }
        }
    }
    return pageFaults;
}

int main(){
    int Q, N, x, y;
    scanf("%d", &Q);
    int *quadros = malloc(sizeof(int)*Q);
    scanf("%d", &N);
    int *vetor = malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
       scanf("%d", &vetor[i]);
    }
    printf("%d\n", otm(quadros, vetor, Q, N));
    return 0; 
}