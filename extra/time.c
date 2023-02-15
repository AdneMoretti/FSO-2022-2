#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    struct timeval initial_time, final_time;
    char exec[256];
    char arg[256];
    int pid, status;
    double time = 0;
    int error;
    double interval;
    
    while (scanf("%s %s", exec, arg) == 2) {
        gettimeofday(&initial_time, NULL);
        fflush(stdout);
        pid = fork();

        if(pid == 0) {
            execl(exec, exec, arg, NULL);
            printf("> Erro: %s\n", strerror(errno));
            fflush(stdout);
            fclose(stdin);
            exit(errno);
        } 
        else if(pid > 0) {
            waitpid(pid, &status, WUNTRACED);
            gettimeofday(&final_time, NULL);
            interval = (final_time.tv_sec - initial_time.tv_sec) + (final_time.tv_usec - initial_time.tv_usec)/1000000.0;
            printf("> Demorou %.1lf segundos, retornou %d\n", interval, WEXITSTATUS(status));
            fflush(stdout);
            time += interval;
        } 
        else{
            printf("Error: %s\n", strerror(errno));
            fflush(stdout);

        }
    }
    printf(">> O tempo total foi de %.1lf segundos\n", time);
    fflush(stdout);

    return 0;
}