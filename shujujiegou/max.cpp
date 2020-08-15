#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a = "abc";
	string b = "babc";

	cout<<max(a,b)<<endl;
	cout<<a+to_string(2)<<endl;

	string c = "1->2->3->4->";
	int pos = c.rfind("-");
	cout<<pos<<endl;
	c = c.substr(0,pos);
	cout<<c<<endl;
	pos = c.rfind(">");
	c = c.substr(0,pos+1);
	cout<<c<<endl;


	


	return 0;
}
