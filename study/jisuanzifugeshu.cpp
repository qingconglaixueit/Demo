#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
	char c;
    while(cin>>str>>c)
    {
        int n = str.size();
        vector<int> helper(26,0);
        for(int i =0;i<n;i++)
        {
            if(str[i] >='A' && str[i]<='Z')
            {
                helper[str[i]-'A']++;
            }else if(str[i] >='a' && str[i]<='z')
            {
                helper[str[i]-'a']++;
            }
        }
        if(c >='A' && c<='Z') cout<<helper[c-'A']<<endl;
        else if(c >='a' && c<='z') cout<<helper[c-'a']<<endl;
    }
    
    return 0;
}
