#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n,oper;
    while(cin>>n>>oper)
    {
        string name;
        int grade;
        vector<string> res[101];//因为分数位0-100分
        for(int i = 0;i<n;i++)
        {
            cin>>name>>grade;
            res[grade].push_back(name);
        }
        
        if(oper)
        {
            for(int i = 0;i<101;i++)
            {
                for(int j = 0;j<res[i].size();j++)
				{
                    cout<<res[i][j]<<" "<<i<<endl;
				}
            }
        }
        else
        {
            for(int i = 100;i>=0;i--)
            {
                for(int j = 0;j<res[i].size();j++)
				{
                    cout<<res[i][j]<<" "<<i<<endl;
				}
            }
        }
    }
    
    
    
    
    return 0;
}
