#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "phdfphjkl";
	string str2 = "fph";

	cout<<str.find_first_not_of(str2)<<endl;




	return 0;
}
