#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int max = 0;
        int len = 0;
        while(n>0)
        {
            if(n%2 == 1) len++;
            else
            {
                max = max<len?len:max;
                len = 0;
            }
            n = n/2;
        }
        max = max<len?len:max;
        cout<<max<<endl;
    }
    
    
    
    
    
    return 0;
}
