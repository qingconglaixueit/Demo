#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int res = 1;
        for(int i = 1;i<=n;i++)
            res += 2*(i-1);
        for(int i = 0;i<n;i++)
        {
            if(i == 0)    cout<<res+2*i;
            else          cout<<"+"<<res+2*i;
        }
        cout<<endl;
    }
    
    
    
    
    
    return 0;
}

