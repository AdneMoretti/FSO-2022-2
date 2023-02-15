#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int dado;
    struct no *prox; 
} no; 

no *enfileira(no *p, int x){
    no *novo = malloc(sizeof(no));
    if(novo == NULL) return NULL;
    novo->prox = p-> prox;
    p->prox = novo;
    p->dado = x;
    // p = novo;
    return novo; 
}

int desenfileira(no *p, int *y){
    no *lixo = p->prox;
    if(lixo==NULL) return 0;
    p-> prox = lixo ->prox;
    *y = lixo->dado;
    free(lixo);
    return 1;
}

int busca(int x, no *le){
    for(no *inicio = le -> prox; inicio->prox!=NULL;inicio = inicio->prox){
        if(inicio->dado == x) {
            return 1;
        }
    }
    return 0;
}

void imprime(no *le){
    for(no *inicio = le -> prox; inicio->prox!=NULL;inicio = inicio->prox){
        printf("%d", inicio->dado);
    }
    printf("\n");
}
int main(){
    int Q, N, x, pageFaults, y;
    scanf("%d", &Q);
    scanf("%d", &N);
    pageFaults = 0;
    no *inicio = malloc(sizeof(no));
    no *fim = malloc(sizeof(no));
    inicio->prox = fim;
    if(Q>0 && N>0){
        scanf("%d", &x);
        fim = enfileira(fim, x);
        pageFaults++;
        for(int i = 1; i<N;i++){
            scanf("%d", &x);
            if(!busca(x, inicio)){
                pageFaults++;
                fim = enfileira(fim, x);
                if(pageFaults>Q) desenfileira(inicio, &y);
            }
        }
    }
    printf("%d\n", pageFaults);
    return 0; 
}