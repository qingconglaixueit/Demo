#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int m[10]={0};
        int x[10]={0};
        for(int i = 0;i<n;i++)
            cin>>m[i];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        
        vector<int> weight;
        weight.push_back(0);//现将0放进数组，因为称重重量包括0
        //将第一种砝码的重量，可以称出的可能性放进数组中，作为之后的比较作为基础(如果用set的方法，就不需要先把)
       // for(int i = 1;i<=x[0];i++)
        //{
        //    weight.push_back(i*m[0]);
        //}
        //开始进行逐个砝码进行比较和确认最终情况
        for(int i = 0;i<n;i++)
        {
            int len = weight.size();
            for(int j = 1;j<=x[i];j++)
            {
                int tmp = j*m[i];
                if(i == 0)    weight.push_back(tmp);
                for(int z = 0;z<len;z++)
                {
                    int res = weight[z] + tmp;
                    if(find(weight.begin(),weight.end(),res) == weight.end())//如果当前计算的重量数组里面没有，那么就放进去
                        weight.push_back(res);
                }
            }
        }
        cout<<weight.size()<<endl;
    }
    
    
    
    
    
    return 0;
}
