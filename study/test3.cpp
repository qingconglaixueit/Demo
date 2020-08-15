#include <iostream>
#include <string>

using namespace std;

int main()
{

	string str;
	while(cin>>str)
	{
		str.erase(3,1);
		cout<<str<<endl;

	}


	return 0;
}
