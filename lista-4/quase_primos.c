#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

struct parametro_thread
{
  int n;
  pthread_t tid;
  int result;
}typedef parametro_thread;


int calcula_primo(int num){
    if(num <= 508079){
        return 508079;
    }
    else{
    while(1){
    int invalido = 0;
        double raiz = sqrt((double)num);
        int count=0;
        if(num % 2 != 0 && num % 3 !=0 && num %5!=0 && num%7!=0){
                for(int i=11;i<raiz;i+=2){
                    if(num%i==0){
                        count++;
                    }
                }
                if(count>10&&num){
                    return num;
                }
            }
            num++;
        }
    }

}


void *calcula_primos(void *parametro){
    parametro_thread *p = parametro;
    int num = p->n; 
    p->result = calcula_primo(num);
    pthread_exit(NULL);
}

int main(){
    int n;
    scanf("%d", &n);

    int acabou = 0;
    int acabou2 = 0;
    while(1){
        int n1, n2, n3;
        int result;
        if(scanf("%d", &n1) == EOF){
            break;
        }

        if(scanf("%d", &n2) == EOF){
            acabou=1;
        }

        if(scanf("%d", &n3) == EOF){
            acabou2=1;
        }

        parametro_thread PARAMETRO1;
        parametro_thread PARAMETRO2;

        PARAMETRO1.n = n1;
        pthread_create(&PARAMETRO1.tid, NULL, &calcula_primos, &PARAMETRO1);
        if(!acabou){
            PARAMETRO2.n = n2;
            pthread_create(&PARAMETRO2.tid, NULL, &calcula_primos, &PARAMETRO2);
        }
        if(!acabou2) result = calcula_primo(n3);

        pthread_join(PARAMETRO1.tid, NULL);
        if(!acabou){
            pthread_join(PARAMETRO2.tid, NULL);
        }

        printf("%d\n", PARAMETRO1.result);
        if(!acabou) printf("%d\n", PARAMETRO2.result);
        if(!acabou2) printf("%d\n", result);
    }
}