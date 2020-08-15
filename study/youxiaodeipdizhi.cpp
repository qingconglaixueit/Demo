#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;


int validmask(char * mask)
{
    unsigned int n[4],res = 0;
    int i ;
    sscanf(mask,"%u.%u.%u.%u",&n[3],&n[2],&n[1],&n[0]);
    if(n[3] == 255 && n[2] == 255 && n[1] == 255 && n[0]== 255)
        return 0;
    for(i = 0;i<4;i++)
    {
        res += n[i]<<(i*8);
    }
    res = ~res +1;
    if(res & (res - 1) == 0)    return 1;
    return 0;
}

int main()
{
    char str[50];
    int a = 0,b=0,c=0,d=0,e=0,err=0,pri=0;
    while(fgets(str,50,stdin))
    {
        char *p = str;
        char ip[2][20];
        int i = 0;
        int maskflag = 0;
        while((p = strtok(p,"~") )!= NULL)
        {
            strcpy(ip[i],p);
            i++;
            p = NULL;
            if(i == 2)    i=0;
        }
        maskflag = validmask(ip[1]);
        if(maskflag)
        {
            struct in_addr st;
            unsigned int ip1,ip2;
            int valid = inet_pton(AF_INET,ip[0],(void *)&st);
            sscanf(ip[0],"%u.%u",&ip1,&ip2);
            if(valid)
            {
                if(ip1<127)    a++;
                else if(ip1<192)    b++;
                else if(ip1<224)    c++;
                else if(ip1<240)    d++;
                else if(ip1<256)    e++;
                
                if(ip1 == 10 || (ip1==172 && ip2>=16 && ip2<=31) ||(ip1 == 192 && ip2== 168))
                {
                    pri++;
                }
            }else
                err++;
        }else
        {
            err++;
        }
    }
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<err<<" "<<pri<<endl;
    
    
}
