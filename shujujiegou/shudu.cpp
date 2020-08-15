#include <iostream>

using namespace std;
int flag = 0;
int a[9][9];

bool isok(int n,int k)
{
    int x = n/9;
    int y = n%9;
    for(int i=0;i<9;i++)
    {
        if(a[x][i] == k)    return false;
    }
    
    for(int i=0;i<9;i++)
    {
        if(a[i][y] == k)    return false;
    }
    
    x = x/3 *3;
    y = y/3 *3;
    for(int i = x;i<x+3;i++)
    {
        for(int j = y;j<y+3;j++)
        {
            if(a[i][y] == k)    return false;
        }
    }
    return true;
}

void dfs(int n)
{
    if(n > 80)
    {
        flag =1;
        return ;
    }
    int x = n/9;
    int y = n%9;
    if(a[x][y] != 0)
    {
        dfs(n+1);
    }
    else
    {
        for(int i = 1;i<=9;i++)
        {
            if(isok(n,i))
            {
                a[x][y] = i;
                dfs(n+1);
                if(flag == 1)
                    return;
                else
                    a[x][y] = 0;
            }
        }
    }
    
}
int main()
{
    for(int i = 0;i<9;i++)
        for(int j = 0;j<9;j++)
            cin>>a[i][j];
    dfs(0);
    
    for(int i = 0;i<9;i++)
    {
        for(int j = 0;j<9;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    
    
    return 0;
}
