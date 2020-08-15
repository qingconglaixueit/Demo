#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        string name[n];
        vector<int> getpiao(n,0);
        for(int i = 0;i<n;i++)
            cin>>name[i];
        
        int m;
        cin>>m;
        int res = m;
        for(int i = 0;i<m;i++)
        {
            string tmp;
            cin>>tmp;
            for(int j = 0;j<n;j++)
            {
                if(tmp == name[j])
                {
                    getpiao[j]++;
                    res --;
                }
            }
        }
        
        for(int i = 0;i<n;i++)
            cout<<name[i]<<" : "<<getpiao[i]<<endl;
        cout<<"Invalid : "<<res<<endl;
    }
    
    
    
    
    
    return 0;
}
