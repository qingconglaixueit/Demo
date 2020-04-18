#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "odd.h"




int main(int argc,char *argv[])
{

	int a = 5;
	int b = 6;
	int c = add(a,b);
	int d = odd(a,b);

	printf("c = %d\n",c);


	return 0;
}
