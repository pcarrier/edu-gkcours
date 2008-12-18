#include <stdlib.h>
#include <stdio.h>

void pi(char *msg) {
	printf("%s: PID: %i, PPID: %i\n",msg,getpid(),getppid());
}

void makesons(int nb) {
	int remaining = nb;
	while (remaining) {
		if (fork()) {
			pi("Hello!");
			wait();
			--remaining;
		}
		else {
			pi("HaAaa");
			if(remaining==3) remaining = 2;
			else remaining = 0;
		}
	}
}

int main(int argc,char **argv,char **envp) {
	pi("Let's have fun");
	makesons(3);
	wait();
	return EXIT_SUCCESS;
}
