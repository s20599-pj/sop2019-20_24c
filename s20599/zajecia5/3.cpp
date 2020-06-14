#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t masterPid = getpid();

    for(int i = 0; i<100; i++){
        pid_t child = fork();
        if(i == 99 && child == 0){
            sleep(20);
        }
        if(child > 0){
            wait(NULL);
            break;
        }
    }
    return 0;
}