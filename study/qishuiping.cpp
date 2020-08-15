#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int res = 0;
        while(n)
        {
            res += n/3;
            n = n/3 + n%3;
            if(n == 2)    
            {
                res++;
                n = 0;
            }else if(n == 1)    n= 0;
        }
        cout<<res<<endl;
    }
    
    
    
    
    
    return 0;
}
