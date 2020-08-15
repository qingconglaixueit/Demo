#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int res = 0;
        for(int i = 0;i<=n;i++)
        {
            if(i<1e1)
            {
                res = (i%10 == (i*i)%10)?res + 1:res;
            }
            else if(i<1e2)
            {
                res = (i%100 == (i*i)%100)?res + 1:res;
            }
            else if(i<1e3)
            {
                res = (i%1000 == (i*i)%1000)?res + 1:res;
            }
            else if(i<1e4)
            {
                res = (i%10000 == (i*i)%10000)?res + 1:res;
            }
        }
        
        cout<<res<<endl;
        
    }
    
    
    
    
    
    return 0;
}
