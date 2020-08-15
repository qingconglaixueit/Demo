#include <iostream>
#include <string>

using namespace std;

int main()
{

	int curr=1,top=1,n;
	string str;
	while(cin>>n>>str)
	{
	if(n<=4)
	{ 
		for(int i =0;i<str.size();i++)
		{
			if(curr == 1 && str[i] == 'U') {curr=n;}
			else if(curr == n && str[i] == 'D') {curr = 1;}
			else if(str[i] == 'U') curr--;
			else  curr++;
		}
		
		for(int i =1;i<=n-1;i++)
		{
			cout<<i<<" ";
		}
		cout<<n<<endl;
		cout<<curr<<endl;
		
	}
	else
	{
		for(int i = 0;i<str.size();i++)
		{
			if(top == 1 && curr == 1 && str[i] == 'U') {curr = n,top = n-3;}
			else if(top == n-3 && curr == n && str[i] == 'D'){curr = 1;top=1;}
			else if(top != 1 && curr == top && str[i] == 'U') {top--;curr--;}
			else if(top != n-3 && curr == top+3 && str[i] == 'D') {top++;curr++;}
			else if(str[i] == 'U') {curr--;}
			else {curr++;}
		}

		for(int i = top;i<=top+2;i++)
		{
			cout<<i<<" ";
		}
		cout<<top+3<<endl;
		cout<<curr<<endl;
	}
	}




	return 0;
}
