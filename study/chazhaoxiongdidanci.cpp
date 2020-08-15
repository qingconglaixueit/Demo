#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isbro(string str,string s)
{
    if(str.size() == s.size())
    {
        if(str == s)    return false;
        sort(str.begin(),str.end());
        sort(s.begin(),s.end());
        if(str == s)    return true;
    }
    return false;
}

int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> vec;
        for(int i = 0;i<n;i++)
        {
            string tmp;
            cin>>tmp;
            vec.push_back(tmp);
        }
        string s,res;
        int index,count=0;
        cin>>s>>index;
        for(int i = 0;i<vec.size();i++)
        {
            if(isbro(vec[i],s))
            {
                count++;
                if(count == index)    res = vec[i];
            }
        }
        cout<<count<<endl;
        cout<<res<<endl;
            
    }
    
    
    
    
    return 0;
}
