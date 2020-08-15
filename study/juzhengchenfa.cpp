#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    while(cin >> n>>m>>k)
    {
        int a[n][m];
        int b[m][k];
        int c[n][k];
        
        for(int i = 0;i<n;i++)
        {
            for(int j= 0 ;j<m;j++)
            {
                int tmp;
                cin>>tmp;
                a[i][j] = tmp;
            }
        }
        
        for(int i = 0;i<m;i++)
        {
            for(int j= 0 ;j<k;j++)
            {
                int tmp;
                cin>>tmp;
                b[i][j] = tmp;
            }
        }
        
        for(int i =0;i<n;i++)
        {
             for(int j = 0;j<k;j++)
             {
                 int tmp = 0;
                 int res = 0;
                 while(tmp <m)
                 {
                     res += a[i][tmp] * b[tmp][j];
                     tmp++;
                 }
                 c[i][j] = res;
                 cout<<c[i][j]<<" ";
             }
            cout<<endl;
        }
    }
    
    
    
    
    return 0;
}
