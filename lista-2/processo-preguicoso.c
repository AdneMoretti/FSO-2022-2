#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int count = 0;
void tratamento(int sig){
    if(sig==SIGUSR1){
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    }
    if(sig==SIGALRM){
        if(count==2){
            printf("Os incomodados que se mudem, tchau\n");
            exit(0);
        }
        else{
            printf("Ai que sono, quero dormir mais um pouco\n");
            count++;
        }
    }


}

int main(void){
    signal(SIGUSR1, tratamento);
    signal(SIGALRM, tratamento);

    while(1){
        pause();
    }
    return 0;
}