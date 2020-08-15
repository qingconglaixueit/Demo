#include <iostream>
#include <string>

using namespace std;

void encrypt(string & str1)
{
    for(int i =0;i<str1.size();i++)
    {
        if(str1[i]>='0' && str1[i]<='9')
        {
            if(str1[i]=='9')    str1[i] = '0';
            else    str1[i] = str1[i]+1;
        }
        else if(str1[i]>='a' && str1[i]<='z')
        {
            if(str1[i] == 'z')    str1[i] = 'A';
            else    str1[i] = str1[i]-32+1;
  
        }
        else if(str1[i]>='A' && str1[i]<='Z')
        {
            if(str1[i] == 'Z')    str1[i] = 'a';
            else str1[i] = str1[i] + 32 +1;
        }  
    }
}

void uncrypt(string & str1)
{
    for(int i = 0;i<str1.size();i++)
    {
        if(str1[i]>='0' && str1[i]<='9')
        {
            if(str1[i]=='0')    str1[i] = '9';
            else    str1[i] = str1[i]-1;
        }
        else if(str1[i]>='a' && str1[i]<='z')
        {
            if(str1[i] == 'a')    str1[i] = 'Z';
            else    str1[i] = str1[i]-32-1;
        }
        else if(str1[i]>='A' && str1[i]<='Z')
        {
            if(str1[i] == 'A')    str1[i] = 'z';
            else str1[i] = str1[i] + 32 -1;
        }  
    }
}

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        encrypt(str1);
        uncrypt(str2);
        cout<<str1<<endl;
        cout<<str2<<endl;
    }
    return 0;
}
