#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str="qingbing@qq.com";
	int pos = str.find("@");
	cout<<str.substr(0,pos)<<endl;
	return 0;
}
