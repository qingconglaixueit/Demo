#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    int oper;
    while(cin >> str>>oper)
    {
        if(oper == 1)
        {
            string tmp;
            for(int i = 0;i<str.size();i++)
            {
                if(str[i]>='a' && str[i] <='z')
                {
                    tmp.push_back(str[i]);
                }
            }
            reverse(tmp.begin(),tmp.end());
            int i,j;
            for(i =0,j=0;i<str.size()&&j<tmp.size();i++)
            {
                if(str[i]>='a' && str[i] <='z')     cout<<tmp[j++];
                else     cout<<str[i];
            }
            if(i < str.size())
            {
                cout<<str.substr(i,str.size()-i)<<endl;
            }
            
            
        }
        else if(oper == 2)
        {
            
        }
        else if(oper == 3)
        {
            
        }
        
        
        
    }
    
    
    
    
    return 0;
}

