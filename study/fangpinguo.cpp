#include <iostream>

using namespace std;

int getapples(int m,int n)
{
    if(m<0)    return 0;
    if(m == 1 || n == 1)    return 1;
    return getapples(m,n-1) +getapples(m-n,n); 
}

int main()
{
    int m, n;
    while(cin>>m>>n)
    {
        cout<<getapples(m,n)<<endl;
    }
    
    
    
    
    
    return 0;
}
