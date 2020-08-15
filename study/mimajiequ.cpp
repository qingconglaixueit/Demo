#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int max=0;
        int start=0;
        int end = 0;
        for(int i = 0;i<str.size();i++)
        {
            if(i+1 < str.size() && str[i] == str[i+1])
            {
                start = i;
                end = i+1;
                int tmp= 0;
                while(str[start] == str[end])
                {
                    tmp ++;
                    if(start - 1 >=0)    start--;
                    else    break;
                    if(end + 1 < str.size()) end++;
                    else break;
                }
                max = max<(2*tmp)?(2*tmp):max;
            }
            else if(i+2 < str.size() && str[i] == str[i+2])
            {
                start = i;
                end = i+2;
                int tmp= 0;
                while(str[start] == str[end])
                {
                    tmp ++;
                    if(start - 1 >=0)    start--;
                    else    break;
                    if(end + 1 < str.size()) end++;
                    else break;
                }
                max = max<(2*tmp+1)?(2*tmp+1):max;
            }
        }
        cout<<max<<endl;
        
        
        
    }
    
    
    
    
    
    
    return 0;
}
