#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void pi(char *msg) {
	printf("%s: PID: %i, PPID: %i\n",msg,getpid(),getppid());
}

void makesons(int nb) {
	int remaining = nb;
	while (remaining) {
		pid_t pid = fork();
		if (pid > 0) {
			pi("Hello!");
			wait(NULL);
			--remaining;
		}
		else if (pid == 0) {
			pi("HaAaa");
			if(remaining==3) remaining = 2;
			else remaining = 0;
		}
		else {
			perror("fork");
			break;
		}
	}
}

int main(int argc,char **argv,char **envp) {
	pi("Let's have fun");
	makesons(3);
	wait(NULL);
	return EXIT_SUCCESS;
}
