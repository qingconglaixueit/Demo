#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void printnum(int &num)
{	
	while(1)
	{
		cout<<"num == " <<num<<endl;
		sleep(1);
	}
}

int main()
{
	
	int a = 1,b=2;
	thread one(printnum,std::ref(a));
	thread two(printnum,std::ref(b));

	one.join();
	two.join();
	
}
