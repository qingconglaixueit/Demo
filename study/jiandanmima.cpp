#include <iostream>
#include <string>

using namespace std;

int main()
{
    int helper[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    string str;
    while(cin>>str)
    {
        for(int i = 0;i<str.size();i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                if(str[i]=='Z')    str[i] = 'a';
                else    str[i] = str[i]+33;
            }
            else if(str[i]>='a' && str[i]<='z')
            {
                str[i] = helper[str[i] - 'a']+'0';
            }
        }
        cout<<str<<endl;
    }
    
    
    
    
    return 0;
}
