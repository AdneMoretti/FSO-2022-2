#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct Info{
    int *vetor;
    int n;
} Info; 


int comparator(const void *p1, const void *p2){
    return (*(int*)p1 - *(int*)p2);
}

void *order(void *argumentos){
    Info * arg = (Info*) argumentos;
    qsort(arg->vetor, arg->n , sizeof(int), comparator);
}

int main(){
    int n;
    scanf("%d", &n);
    Info info1;
    Info info2;
    int *vetor1 = malloc(sizeof(int)*n);
    int *vetor2 = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d", &vetor1[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &vetor2[i]);
    }
    pthread_t tid1;
    info1.vetor = vetor1;
    info1.n = n;
    pthread_create(&tid1, NULL, &order, &info1);
    info2.vetor = vetor2;
    info2.n = n;
    pthread_t tid2;
    pthread_create(&tid2, NULL, &order, &info2);
    pthread_join(tid2, NULL);
    pthread_join(tid1, NULL);
    // sleep(1);
    for(int i=0;i<n;i++){
        if(info1.vetor[i]!= info2.vetor[i]){
            printf("Diferentes\n");
            break;
        }
        if(info1.vetor[i]== info2.vetor[i] && i==n-1){
            printf("Mesmos elementos\n");
        }
    }

}