#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const string helper1 = "0123456789abcdefABCDEF";
const string helper2 = "084C2A6E195D3B7F5D3B7F";

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        string s = str1 + str2;
        string tmp1,tmp2;
        int len = s.size();
        for(int i=0;i<len;i++)
        {
            if(i%2 == 0)    tmp1 += s[i];
            else    tmp2 += s[i];  
        }
        sort(tmp1.begin(),tmp1.end());
        sort(tmp2.begin(),tmp2.end());
        s.clear();
        
        for(int i =0,j=0,k=0;i<len;i++)
        {
            if(i%2 == 0)    s += tmp1[j++];
            else            s += tmp2[k++];
        }
        
        for(int i = 0;i<s.size();i++)
        {
            if(helper1.find(s[i]) != -1)
            {
                s[i] = helper2[helper1.find(s[i])];
            }
        }
        cout<<s<<endl;
    }

    return 0;
}


