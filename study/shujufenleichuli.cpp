#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int m,n;
    while(cin>>m)
    {
        vector<int> R;
        for(int i = 0;i<m;i++)
        {
            int tmp;
            cin>>tmp;
            R.push_back(tmp);
        }
        cin>>n;
        vector<int> I;
        for(int i = 0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            I.push_back(tmp);
        }
        sort(I.begin(),I.end());
        vector<int> res;
        vector<int> num;
        for(int i = 0;i<n;i++)
        {
            if(i !=0  && I[i] == I[i-1])    continue;
            
            int count = 0;
            int flag = 0;
            for(int j = 0;j<m;j++)
            {
                int tmp = R[j];
                while(tmp)
                {
                    if(tmp%10 == I[i] || tmp%100 == I[i] || tmp%1000 == I[i])
                    {
                        if(flag == 0)
                        {
                            flag = 1;
                            count++;
                            num.push_back(I[i]);
                            res.push_back(j);
                            res.push_back(R[j]);
                        }
                        else
                        {
                            count++;
                            res.push_back(j);
                            res.push_back(R[j]);
                        }
                        break;
                    }
                    
                    tmp/=10;
                }
            }
            if(count != 0)    
            {
                 num.push_back(count);
            }
        }
        
        int start = 0;
        int j;
        cout<<num.size()+res.size()<<" ";
        for(int i = 0;i<num.size();i++)
        {
            cout<<num[i]<<" "<<num[++i]<<" ";
            for(j = start;j<start+num[i]*2;j++)
            {
                cout<<res[j]<<" ";
            }
            start = j;
        }
        cout<<endl;
    }
    
    
    
    
    
    return 0;
}
