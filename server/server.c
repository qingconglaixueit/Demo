#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define SERVER_PORT 9999

int main(int argc ,int * argv[])
{

	int fd;
	int cfd;
	int clen;
	int i = 0;
	struct sockaddr_in addr , caddr;
	char buff[4096];
	int ret;
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1)
	{
		printf("fd error!!");
		return -1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(SERVER_PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(fd,(struct sockaddr *)&addr,sizeof(addr));
	
	listen(fd,128);
	clen = sizeof(caddr);
	cfd = accept(fd,(struct sockaddr *)&caddr,&clen);
	if(cfd == -1)
	{
		printf("cfd erro !!");
		return -1;
	}
	
	while(1)
	{	
		ret = read(cfd,buff,sizeof(buff));
		write(STDOUT_FILENO,buff,ret);
		for(i = 0;i<ret;i++)
		{
			buff[i] = toupper(buff[i]);
		}

		write(cfd,buff,ret);
	}

	close(fd);
	close(cfd);

	
	return 0;

}

