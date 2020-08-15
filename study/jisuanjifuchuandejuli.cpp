#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getmaxinstance(string a ,string b)
{
    int n = (int)a.size();
    int m = (int)b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[0][0] = 0;
    for(int i = 1;i<=n;++i)    dp[i][0] = i;
    for(int i = 1;i<=m;++i)    dp[0][i] = i;
    for(int i = 1;i<=n;++i)
    {
        for(int j = 1;j<=m;++j)
        {
            int one = dp[i-1][j]+1,two = dp[i][j-1]+1,three = dp[i-1][j-1];
            if(a[i-1] != b[j-1])    three += 1;
            dp[i][j] = min(min(one,two),three);
        }
    }
    return dp[n][m];
}

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        cout<<getmaxinstance(str1,str2);
    }
    
    
    return 0;
}
