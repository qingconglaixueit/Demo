#include <iostream>

using namespace std;

int main()
{
	int n;
	int tmp[16] = {0};
	int res = 0;	
	cin >> n;
	while(n)
	{
		if(tmp[n%10] == 0)
		{
			tmp[n%10] = 1;
			res = res * 10 + n%10;
		}
		n = n/10;
	}
	cout<<res<<endl;


	return 0;
}
