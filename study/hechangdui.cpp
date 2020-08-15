#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void calinc(vector<int> num , vector<int> &inc)
{
    for(int i = 0;i<num.size();i++)
    {
        for(int j = i-1;j>=0;j--)
        {
            if(num[j] < num[i] && inc[j]+1 > inc[i])
            {
                inc[i] = inc[j]+1;
            }
        }
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> num;
        vector<int> inc(n,1);
        vector<int> dec(n,1);
        int max = 0;
		int tmp;
        for(int i = 0;i<n;i++)
        {
			cin>>tmp;
			num.push_back(tmp);
        }
        calinc(num,inc);
        reverse(num.begin(),num.end());//翻转，为了找用递增的方法找递减序列
        calinc(num,dec);//这一步目前dec是递增序列
        reverse(dec.begin(),dec.end());//dec目前是递减序列了
        
        for(int i = 0;i<n;i++)
        {
            if(max < inc[i] + dec[i])
                max = inc[i] + dec[i];
        }
        cout<<n-max+1<<endl;
    }
    return 0;
}
