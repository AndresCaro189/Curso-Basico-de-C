#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int lenghts[argc];
   
    for(int i=0; i<argc-1 ;i++){
        lenghts[i] = strlen(argv[i+1]);
        // printf("%d\n", lenghts[i]);
    }
    int max;
    for(int i=0; i<argc; i++){
        if(lenghts[i]>max){
            max = lenghts[i];
        }
    }
    char * longest="";
    for(int i=1; i<argc; i++){
        if(strlen(argv[i])>strlen(longest)){
            longest = argv[i];
        }
    }
    printf("Longest String = %s \n", longest);
    printf("Max Lenght = %d \n", max);
    return 0;
}