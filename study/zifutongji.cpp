#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int helper[256]={0};
        int max = 0;
        for(int i = 0;i<str.size();i++)
        {
            helper[str[i]]++;
            if(helper[str[i]] > max) max = helper[str[i]];
        }
        while(max)
        {
            for(int i = 0;i<256;i++)
            {
                if(helper[i] == max)
                    cout<<(char)i;
            }
            max--;
        }
        cout<<endl;
    }
    
    
    
    
    
    
    return 0;
}




