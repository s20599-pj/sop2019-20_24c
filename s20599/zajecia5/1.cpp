#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[]) {
	if (fork() != 0){
        wait(NULL);
        printf("Rodzic: PID: %d PPID: %d\n", getpid(), getppid());
        }
	else
        printf("Dziecko: PID: %d PPID: %d\n", getpid(), getppid());
	return 0;
}