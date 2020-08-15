#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/wait.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>


void catch_child(int signum)
{

	while(waitpid(0,NULL,WNOHANG) > 0);

}

int main()
{
	int fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1)
	{
		printf("socket error\n");
		return 0;
	}

	struct sockaddr_in addr,caddr;
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9922);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(fd,(struct sockaddr *)&addr,sizeof(addr));
	
	listen(fd,128);
	
	int clen = sizeof(caddr);
	
	pid_t pid;
	int cfd;
	while(1)
	{
		cfd = accept(fd,(struct sockaddr *)&caddr,&clen);
		if(cfd == -1)
		{
			printf("accept error\n");
			return 0;
		}

		pid_t pid = fork();
		if(pid == -1)
		{
			printf("----fork error");
			return 0;
		}	
		else if(pid == 0)
		{
			close(fd);
			break;
			
		}
		else
		{
			close(cfd);
			struct sigaction act;
			act.sa_handler = catch_child;
			sigemptyset(&act.sa_mask);
			act.sa_flags = 0;
			int ret = sigaction(SIGCHLD,&act,NULL);
			if(ret != 0)
			{
				printf("sigaction error\n");
				return 0;
			}
			continue;
		}

	}

	if(pid == 0)
	{
		char client_ip[4096]={0};
		printf("client ip = %s, port = %d\n",inet_ntop(AF_INET,&caddr.sin_addr.s_addr,client_ip,sizeof(client_ip)),ntohs(caddr.sin_port));
		char buff[4096]={0};
		int ret;	
		while(1)
		{
		ret = read(cfd,buff,sizeof(buff));
		if(strcmp(buff,"quit") == 0)
		{
			write(cfd,"you quit",9);
			break;
		}
		for(int i = 0;i<ret;i++)
			buff[i] = toupper(buff[i]);
		write(STDOUT_FILENO,buff,ret);
		write(cfd,buff,ret);
		}
	}
	close(fd);

	return 0;
}
