#include <stdio.h>
#include <string.h>

int compare(FILE *file1, FILE *file2){
    fseek(file1, 0, SEEK_END);
    long int size1 = ftell(file1);
    fseek(file1, 0, SEEK_SET);
    fseek(file2, 0, SEEK_END);
    long int size2 = ftell(file2);
    fseek(file2, 0, SEEK_SET);
    if (size1 != size2) {
        return 0;
    }
    else{
        unsigned char byte1; 
        unsigned char byte2;
        for(long int k = 0; k < size1;k++){
            fread(&byte1, sizeof(unsigned char), 1, file1);
            fread(&byte2, sizeof(unsigned char), 1, file2);
            if(byte1 != byte2){
                return 0;
            }
        }
        return 1;
    }
}

int main(int argc,char **argv) {
    for(int i=1;i < argc-1; i++){
        FILE* file1 = fopen(argv[i], "r");
        for(int j=i+1;j < argc; j++){
            FILE* file2 = fopen(argv[j], "r");
            if (file1 == NULL || file2 == NULL) {
                return 1;
            }
            if(compare(file1, file2)) printf("%s %s iguais\n",  argv[i], argv[j]);
            else printf("%s %s diferentes\n",  argv[i], argv[j]);
            fclose(file2);
        }
        fclose(file1);
        }

    return 0;
} 