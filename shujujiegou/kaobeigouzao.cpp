#include <iostream>
#include <string>

using namespace std;

class A
{
private:
	int value;

public:
	A(int n) {value = n;cout<<"111"<<endl;}
	A(const A &other){value = other.value;cout<<"222"<<endl;}
	void print(){cout<<value <<endl;}
};

int main()
{

	A a =10;
	A b = a;
	b.print();



	return 0;
}


