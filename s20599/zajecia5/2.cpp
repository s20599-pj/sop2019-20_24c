#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int pierwsza(int x){
    for (int i = 2; i <= x/2; i++){
        if ((x % i) == 0)
            return 0; 
    }
    return 1;
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    if(argc == 2){
        if (fork() != 0){
            wait(NULL);
            int suma = 0;
            for(int i = 0; i < n; i++){
                suma += i;
            }
            printf("%d", suma);
            printf("\r\n");
        }
        else{
            for(int i = 1; i < n; i++){
                if(pierwsza(i) == 1)
                    printf("%d ", i);
            }
            printf("\r\n");
        }  
        return 0;
    }
    else
    {
        printf("Nie podano argumentu\r\n");
        return 1;
    }
    
}