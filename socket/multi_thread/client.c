#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>


int main()
{

	struct sockaddr_in  saddr;
	saddr.sin_family =  AF_INET;
	saddr.sin_port = htons(9922);
	inet_pton(AF_INET,"127.0.0.1",&saddr.sin_addr.s_addr);

	int fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1)
	{
		printf("socket error\n");
		return 0;
	}
	int ret = connect(fd,(struct sockaddr *)&saddr,sizeof(saddr));
	if(ret == -1)
	{
		printf("connect error\n");
		return 0;
	}
	
	char buff[4096];
	
	while(1)
	{

		scanf("%s",buff);
		write(fd,buff,strlen(buff));
		write(STDOUT_FILENO,buff,strlen(buff));
	}
	close(fd);
}

