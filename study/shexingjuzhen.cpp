#include <iostream>

using namespace std;

int main()
{
    int n ;
    while(cin>>n)
    {
        int tmp = 1;
        for(int i = 1;i<=n;i++)
        {
            tmp +=i-1;
            int num = tmp;
            for(int j=i;j<=n;j++)
            {
                if(j == i)    cout<<num<<" ";
                else
                {
                    num += j;
                    cout<<num<<" ";
                }
            }
            cout<<endl;
        }
    }
    
    
    
    
    return 0;
}
