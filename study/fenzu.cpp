#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool dfs(int i,int n,vector<int> rest,int resetsum,int sum)
{
    if(i == n)    return abs(resetsum) == abs(sum);
    return dfs(i+1,n,rest,resetsum+rest[i],sum) || dfs(i+1,n,rest,resetsum-rest[i],sum) ;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int sum = 0,sum_5=0,sum_3=0;
        vector<int> rest;
        bool flag = false;
        for(int i = 0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            sum+= tmp;
            if(tmp%5 == 0)    sum_5+=tmp;
            else if (tmp%3 == 0)  sum_3 += tmp;
            else    rest.push_back(tmp);
        }
        if(sum % 2 != 0)    cout<<"false"<<endl;
        else
        {
            sum = abs(sum_5 - sum_3);
            flag = dfs(0,rest.size(),rest,0,sum);
            if(flag)    cout<<"true"<<endl;
            else        cout<<"false"<<endl;
        }
        
        
    }

    return 0;
}
