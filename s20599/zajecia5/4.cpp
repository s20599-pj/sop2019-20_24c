#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t masterPid = getpid();

    for(int i = 0; i<100; i++){
        pid_t child = fork();
        if(child == 0){
            break;
        }
    }
    if(getppid() == masterPid){
        printf("Kolejne dziecko zaczyna czekac\r\n");
        sleep(3);
    }
    if(getpid() == masterPid){
        printf("Rodzic zaczyna czekac\r\n");
        wait(NULL);
    }
    return 0;
}