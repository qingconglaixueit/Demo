#include <iostream>

using namespace std;

int main()
{

	auto lam = []{cout<<"hello lambda"<<endl;};
	lam();


	auto lam2 = []()->int{cout <<"i have return value"<<endl; return 1;};
	auto ret2 = lam2();
	cout<<ret2<<endl;
	return 0;
}
