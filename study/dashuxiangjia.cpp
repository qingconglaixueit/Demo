#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string a,b;
	string res;
	while(cin >> a >> b)
	{
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());

		int n = a.size()>b.size()?a.size():b.size();
		int jinwei = 0;
		for(int i = 0;i<n;i++)
		{
			int anum = i<a.size()?a[i]-'0':0;
			int bnum = i<b.size()?b[i]-'0':0;
			int value = (anum + bnum + jinwei)%10;
			jinwei = (anum + bnum + jinwei)/10;
			res.insert(res.begin(),value+'0');
		}
		if(jinwei == 1)
			res.insert(res.begin(),'1');
		
		cout<<res<<endl;
		res.clear();
		jinwei = 0;
	}


	return 0;
}
