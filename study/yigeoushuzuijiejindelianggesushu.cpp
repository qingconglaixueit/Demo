#include <iostream>
#include <cmath>

using namespace std;

bool isnum(int n)
{
	bool flag = true;
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n%i == 0)
		{
			flag = false;
		}
	}
	return flag;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int a = 0,b=0;
        for(int i =1 ;i<=n;i++)
        {
            if(isnum(i) && isnum(n-i) && (i<=(n-i)))
            {
                a = i;
                b = n-i;
            }
        }
        cout<<a<<endl<<b<<endl;
    }
    
    
    
    
    
    return 0;
}
