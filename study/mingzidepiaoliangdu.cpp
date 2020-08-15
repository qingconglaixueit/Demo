#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        while(n--)
        {
            string str;
            cin >> str;
            int helper[26]={0};
            for(int i = 0;i<str.size();i++)
            {
                if(str[i] >='a' && str[i]<='z')
                    helper[str[i] -'a']++;
                else if(str[i] >='A' && str[i]<='Z')
                    helper[str[i] -'A']++;
            }
            int res = 0;
            for(int i = 0;i<26;i++)
            {
                cout<<i<<"--"<<helper[i]<<endl;
            }
            cout<<"------------"<<endl;
            sort(helper,helper+26);
            
            for(int i = 0;i<26;i++)
            {
                cout<<i<<"--"<<helper[i]<<endl;
            }
            
            for(int i = 0;i<26;i++)
            {
                res += helper[i]*(i+1);
            }
            cout<<res<<endl;
        }
        
    }
    
    
    
    return 0;
}
