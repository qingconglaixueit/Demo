#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG_TEST
#define DEBUG() do{printf("hello world,line %d,file %s,function %s\n",__LINE__,__FILE__,__FUNCTION__);}while(0);
#else
#define DEBUG() do{}while(0);
#endif

void func(int i,int j)
{
	int ret = i/j;
}

int main()
{
	func(5,0);
	return 0;
}
