#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <iostream>
using namespace std;

void parent_process(FILE *f){
    wait(NULL);
    string message;
    printf("Podaj wiadomosc do przekazania(max 1000 znakow): ");
    cin >> message;
    freopen("/tmp/chat","w",f);
    fprintf(f, "%s", message.c_str());
}
void child_process(FILE *f){
    char text[1001];
    fseek(f,0,SEEK_SET);
    fgets(text, 1000, f);
    printf("Wiadomosc: %s\n", text);
}

int main(){
    FILE *f = fopen("/tmp/chat","r+");
    if(fork() != 0){
        parent_process(f);
    }
    else{
        child_process(f);
    }
    fclose(f);
    return 0;
}