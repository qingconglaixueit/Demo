#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str = "abcdefg";
	reverse(str.begin()+1,str.begin()+2+1);
	cout<<str<<endl;

	return 0;
}
