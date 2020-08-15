#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc,char *argv[])
{
	char buf[256]={0};
	strcpy(buf,argv[1]);
	cout<<buf<<endl;

}
