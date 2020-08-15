#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	pid_t pid;
	signal(SIGCHLD,SIG_IGN);
	pid	= fork();
	if(pid == -1)	return -1;
	if(pid == 0)
	{
			printf("i am child...\n");
	}
	else
	{
			printf("i am father\n");
	}
	printf("fork after\n");


	return 0;
}
