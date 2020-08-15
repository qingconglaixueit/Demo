#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        string tmp;
        if(str1.size()>str2.size())
        {
            tmp = str1;
            str1 = str2;
            str2 = tmp;
        }
        int start = 0;
        int max = 0;
        for(int i = 0;i<str1.size();i++)
        {
            for(int j = 0;j<str2.size();j++)
            {
                if(str1[i] == str2[j])
                {
                   // cout<<"str1 i == "<<str1[i]<<endl;
                    int tmpi = i;
                    int tmpj = j;
                    int len = 0;
                    while(str1[tmpi++] == str2[tmpj++]) 
                    {
                        len++;
                    }
                    if(max < len)
                    {
                        start = i;
                        max = len;
                    }
                }
            }
        }
        cout<<str1.substr(start,max)<<endl;
        
    }
    
    
    
    
    
    return 0;
}
