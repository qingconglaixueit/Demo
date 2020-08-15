#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        while(n)
        {
            cout<<n%10;
            n = n/10;
        }
        cout<<endl;
    }
    
    
    
    
    
    return 0;
}
