#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
    
    string str;
    while(getline(cin,str))
    {
        for(int i = 0;i<str.size();i++)
        {
            if(!((str[i]>='A' && str[i<='Z'])||(str[i]>='a' && str[i]<='z')))
            {
                str[i]=' ';
            }
        }
        stringstream ss(str);
        
        string res = "";
        string tmp;
        while(ss>>tmp)
        {
            //cout<<tmp<<endl;
            if(res == "")
            {
                res = tmp;
            }
            else
            {
                res = tmp + " "+ res;
            }
        }
        cout<<res<<endl;
    }
    
    
    
    
    
    
    return 0;
}


