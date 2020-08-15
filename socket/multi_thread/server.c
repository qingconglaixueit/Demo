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
#include <pthread.h>

struct info
{
	struct sockaddr_in conaddr;
	int confd;
};


void* do_child(void * arg)
{
		struct info *my  = (struct info *)arg;
		char client_ip[4096]={0};
		printf("client ip = %s, port = %d\n",inet_ntop(AF_INET,&(*my).conaddr.sin_addr.s_addr,client_ip,sizeof(client_ip)),ntohs(my->conaddr.sin_port));
		char buff[4096]={0};
		int ret;	
		while(1)
		{
			ret = read(my->confd,buff,sizeof(buff));
			if(ret == 0 || ret < 0)
			{
				printf("read data pthread error\n");
				break;
			}
			for(int i = 0;i<ret;i++)
				buff[i] = toupper(buff[i]);
			write(STDOUT_FILENO,buff,ret);
			write(my->confd,buff,ret);
		}
		close(my->confd);
		pthread_exit(0);
}


int main()
{
	int fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1)
	{
		printf("socket error\n");
		return 0;
	}

	int opt = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,(void *)&opt,sizeof(opt));
	
	struct sockaddr_in addr,caddr;
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9922);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(fd,(struct sockaddr *)&addr,sizeof(addr));
	
	listen(fd,128);
	
	int clen = sizeof(caddr);
	
	int cfd;
	struct info t[256];
	int i = 0;
	pthread_t tid;
	memset(t,0,sizeof(struct info) * 256);
	while(1)
	{
		cfd = accept(fd,(struct sockaddr *)&caddr,&clen);
		if(cfd == -1)
		{
			printf("accept error\n");
			return 0;
		}
		t[i].conaddr = caddr;
		t[i].confd = cfd;
		pthread_create(&tid,NULL,do_child,(void *)&t[i]);
		pthread_detach(tid);

		i++;
		
	}
	close(fd);

	return 0;
}
