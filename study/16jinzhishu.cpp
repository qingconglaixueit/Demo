#include <iostream>
#include <string>

using namespace std;


int getnum(string str)
{
	int size = str.size();
	if(size<=2)	return 0;
	
	double res = 0;
	for(int i = 2;i<size;i++)
	{
		int num = 0;
		switch(str[i])
		{
			case 'A':	num = 10;break;
			case 'B':	num = 11;break;
			case 'C':	num = 12;break;
			case 'D':	num = 13;break;
			case 'E':	num = 14;break;
			case 'F':	num = 15;break;
			default:
			if(str[i]>='0' && str[i]<='9')	num = str[i] -'0';
		}
		res = res * 16 + num;
	}
	return res;
}

int main()
{
	#if 0
	string str;
	while(cin>>str)
	{
		cout<<getnum(str)<<endl;
	}
	#endif

	int num;
	while(cin>>hex>>num)
	{
		cout<<num<<endl;
	}



	return 0;
}
