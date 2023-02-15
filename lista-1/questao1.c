#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if(argc==0) printf("0");
    else{
        printf("%d\n", argc-1);
        for(int i=1; i<argc; i++){
            printf("%s\n", argv[i]);
        }
    }


}