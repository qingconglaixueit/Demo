#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<string> str;
    while(cin>>n)
    {
        string tmp;
        for(int i = 0;i<n;i++)
        {
            cin >>tmp;
            if(tmp.size()%8 != 0)
                tmp += "00000000";
            str.push_back(tmp);
        }
        
        for(int i = 0;i<n;i++)
        {
            while(str[i].size()>=8)
            {
                cout<<str[i].substr(0,8)<<endl;
                str[i] = str[i].substr(8);
            }
        }
       
    }
    
    
    
    
    
    return 0;
}
