#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


int main(int argc, char **argv) {
    void *handle;
    char *endptr;
    char *error;
    handle = dlopen (argv[1], RTLD_LAZY);
    if (!handle) {
        printf("nao disponivel\n");
        exit(0);
    }
    double double1 = strtod(argv[4], &endptr);
    int (*imprime)() = dlsym(handle, "imprime");
    int (*calcula)() = dlsym(handle, "calcula");
    int (*trigo)() = dlsym(handle, "trigo");
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    if(!*imprime){
        printf("nao implementado\n");
    }
    else{
        printf ("%d\n", (*imprime)());
    }
    if(!*calcula){
        printf("nao implementado\n");
    }
    else{
        printf ("%d\n", (*calcula)(num1, num2));
    }
    if(!*trigo){
        printf("nao implementado\n");
    }
    else{
        printf ("%d\n", (*trigo)(double1));
    }
    dlclose(handle);
    return 0;
}