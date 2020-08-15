#include <iostream>
#include <string>
#include <algorithm>
//思路：先判断-号的，情况，都为 - ，输出为 - ，其中一个为 -，就要判断是负数大还是负数小
//进行add 和sub函数的编写，要考虑相加后高位的位数会增加1为， 
using namespace std;

string add (string str1,string str2)
{
    string res = "";
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    
    int jinwei = 0;
    for(int i = 0;i<str1.size();i++)
    {
        int tmp = str1[i]-'0' + str2[i] - '0' + jinwei;
        res += (tmp%10) + '0';
        jinwei = tmp /10;
    }
    reverse(res.begin(),res.end());
    if(jinwei == 1)    return "1"+res;
    return res;
}

string sub(string str1,string str2)
{
    string res = "";
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int jiewei = 0;
    for(int i = 0;i<str1.size();i++)
    {
        int prejiewei = jiewei;
        if((str1[i]-'0'-prejiewei) < (str2[i] - '0'))    jiewei =1;
        else jiewei = 0;
       // cout<<"str1 == "<<str1[i]<<" --- str2 == "<<str2[i]<<endl;
        int tmp = (str1[i] -'0')- prejiewei + jiewei * 10 - (str2[i]-'0');
        if(i == str1.size()-1 && (tmp%10) == 0)
            res = res;
        else
            res += (tmp%10)+'0';
        reverse(res.begin(),res.end());
        cout<<"res == "<<res<<endl;
    }
     return res;
}

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        if(str1[0] != '-' && str2[0]!='-')
        {
            if(str1.size()>str2.size())    str2 = string(str1.size()-str2.size(),'0') + str2;
            else    str1 = string(str2.size()-str1.size(),'0') + str1;
                cout<<add(str1,str2)<<endl;
        }
        else if(str1[0] == '-' && str2[0] == '-')
        {
            str1 = str1.substr(1);
            str2 = str2.substr(1);
            if(str1.size()>str2.size())    str2 = string(str1.size()-str2.size(),'0') + str2;
            else    str1 = string(str2.size()-str1.size(),'0') + str1;
            cout<<"-"<<add(str1,str2)<<endl;
        }
        else if(str1[0] == '-' && str2[0] != '-')
        {
            str1 = str1.substr(1);
            if(str1.size()>str2.size()) str2 = string(str1.size()-str2.size(),'0')+str2;
            else str1 = string(str2.size()-str1.size(),'0') + str1;
            cout<<"str1 == "<<str1<<endl;
            cout<<"str2 == "<<str2<<endl;
            if(str1>str2)    cout<<"-"+sub(str1,str2)<<endl;
            else             cout<<sub(str2,str1)<<endl;
        }
        else if(str1[0] != '-' && str2[0] == '-')
        {
            str2 = str2.substr(1);
            if(str2.size()>str1.size()) str1 = string(str2.size()-str1.size(),'0')+str1;
            else str2 = string(str1.size()-str2.size(),'0') + str2;
            if(str1>str2)    cout<<sub(str1,str2)<<endl;
            else             cout<<"-"+sub(str2,str1)<<endl;
        }
    }
    return 0;
}




