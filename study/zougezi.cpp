#include <iostream>

using namespace std;

int res = 0;

void getres(int x,int y,int n,int m)
{
    if(x == n && y == m)
    {
        res++;
        return ;
    }
    
    if(x+1 <= n)    getres(x+1,y,n,m);
    if(y+1 <=m)     getres(x,y+1,n,m);
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        getres(0,0,n,m);
        cout<<res<<endl;
    }
    
    
    
    
    
    
    return 0;
}
