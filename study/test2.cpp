#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

	string str;
	while(1)
	{
		vector<string> ver[5];
		for(int i = 0;i<3;i++)
		{
			cin>>str;
			ver[0].push_back(str);
		}
		
		for(int i =0;i<3;i++)
		{
			cout<<ver[0][i]<<endl;
		}

	}




	return 0;
}
