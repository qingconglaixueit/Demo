#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

bool isprintnum(vector<int> &pushnum,vector<int> &popnum)
{
    stack<int> ss;
    int j = 0;
    for(int i = 0;i<pushnum.size();i++)
    {
        ss.push(pushnum[i]);
        while(j < pushnum.size() && !ss.empty() && ss.top() == popnum[j])
        {
            ss.pop();
            j++;
        }
    }
    return ss.empty();
}

int main()
{
    int n;
    while(cin >>n)
    {
        vector<int> pushnum;
        vector<int> popnum;
        for(int i = 0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            pushnum.push_back(tmp);
            popnum.push_back(tmp);
        }
        sort(popnum.begin(),popnum.end());
        
        do{
            if(isprintnum(pushnum,popnum))
            {
                for(int i = 0;i<popnum.size();i++)
                    cout<<popnum[i]<<" ";
                cout<<endl;
            }
        }while(next_permutation(popnum.begin(),popnum.end()));
    }
    
    
    
    
    
    return 0;
}
