#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int sum = 0;
		int i = 1;
        while(i<=n)
        {
			cout<<"n == "<<i<<endl;
			cout<<" num  == "<<2 + (i-1)*3<<endl;
            sum += (2 + (i-1)*3);
			cout<<"sum == "<<sum<<endl;
			i++;
        }
        cout<<sum<<endl;
    }
    
    
    
    
    
    return 0;
}


