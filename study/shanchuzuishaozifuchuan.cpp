#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        vector<int> tmp(26,0);
        for(int i =0;i<str.size();i++)
            tmp[str[i] - 'a']++;
        int min = 0;
        bool flag = true;
        for(int i =0;i<tmp.size();i++)
        {
            if(tmp[i] > 0)
            {
                if(flag)
                {
                    flag = false;
                    min = tmp[i];
                }
                else
                {
                    if(min > tmp[i])    min = tmp[i];
                }
            }
        }
        string res = "";
         for(int i =0;i<str.size();i++)
         {
             if(tmp[str[i] - 'a'] > min)
             {
                 res += str[i];
             }
         }
        cout<<res<<endl;
        
    }
    
    
    
    return 0;
}
