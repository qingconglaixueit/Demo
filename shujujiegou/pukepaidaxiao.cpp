#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
int judge(vector<string> v)
{
    int flag = 0;
    if(v.size() == 1)    flag = 1;//个子
    else if(v.size() == 2)
    {
        if(v[0] == "joker" || v[1] == "JOKER")    flag = 6;//对王
        else    flag = 2;//普通顺子
    }
    else if(v.size() == 3)    flag = 3;//三个
    else if(v.size() == 4)    flag = 4;//炸弹
    else if(v.size() == 5)    flag = 5;//顺子
    return flag;
}

int myfind(vector<string> base,string v)
{
    for(int i = 0;i<base.size();i++)
    {
        if(v == base[i])    return i;
    }
     return -1;
}
int main()
{
    
    string str;
    while(getline(cin,str))
    {
        int index = str.find("-");
        string str1 = str.substr(0,index);
        string str2 = str.substr(index+1);
        
        vector<string> v1,v2;
        stringstream ss1(str1),ss2(str2);
        string tmp;
        while(ss1>>tmp)    v1.push_back(tmp);
        while(ss2>>tmp)   v2.push_back(tmp);

        int flag1 = judge(v1);
        int flag2 = judge(v2);
        vector<string> base={"3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER"};
        //判断炸弹的情况
        int win = 0;
        if(flag1==6||flag2==6 || flag1==4 || flag2==4)
        {
            if(flag1==6)    win =1;
            else if (flag2==6)    win =2;
            else if(flag1 == flag2 && flag1 == 4)
            {
                auto it1 = myfind(base,v1[0]);
                auto it2 = myfind(base,v2[0]);
                if(it1 != -1 && it2 != -1)
                {
                    if(it1 > it2)    win = 1;
                    else win = 2;
                }else
                {
                    win = 0;
                }
            }
            else if(flag1 == 4 && flag2 != 4)    win = 1;
            else if(flag1 != 4 && flag2 == 4)    win = 2;
        }
        else if(flag1 == flag2)
        {
            auto it1 = myfind(base,v1[0]);
            auto it2 = myfind(base,v2[0]);
            if(it1 != -1 && it2 != -1)
            {
                if(it1 > it2)    win = 1;
                else win = 2;
            }else
            {
                win = 0;
            }
        }else
        {
            win = 0;
        }
        
        if(win == 0)
        {
            cout<<"ERROR"<<endl;
        }
        else if(win == 1)
        {
            for(int i = 0;i<v1.size();i++)
            {
                cout<<v1[i]<<" ";
            }
            cout<<endl;
        }
        else if(win == 2)
        {
            for(int i = 0;i<v2.size();i++)
            {
                cout<<v2[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
