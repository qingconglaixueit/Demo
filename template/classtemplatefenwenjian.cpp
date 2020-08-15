#include <iostream>
#include "person.hpp"
using namespace std;

int main()
{
	person<string,int> p("xiaozhu",10);
	p.printinfo();


	return 0;
}
