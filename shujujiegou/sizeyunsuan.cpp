#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
char c[3];
bool is24(int index,int res,int *a)
{
    if(index == 4)
    {
        if(res == 24)    return true;
        else             return false;
    }
    int flag = 0;
    for(int i = 0;i<4;i++)
    {
        switch(i)
        {
            case 0:
                if(is24(index + 1,res+a[index],a))
                {
                    c[index -1] = '+';
                    flag = 1;break;
                }


            case 1:
                if(is24(index + 1,res-a[index],a))
                {
                    c[index -1] = '-';
                    flag = 1;break;
                }

            case 2:
                if(is24(index + 1,res*a[index],a))
                {
                    c[index -1] = '*';
                    flag = 1;break;
                }
                
            case 3:
                if(is24(index + 1,res/a[index],a))
                {
                    c[index -1] = '/';
                    flag = 1;break;
                }
        }
        if(flag == 1)  break;
    }
    
    if(flag == 1)    return true;
    else             return false;
}

int main()
{
    string s[4];
    while(cin>>s[0]>>s[1]>>s[2]>>s[3])
    {
        int a[4];
        int isexit = 0;
        for(int i = 0;i<4;i++)
        {
            if(s[i] == "joker" || s[i] == "JOKER")
            {
                isexit = 1;
                break;
            }
            if(s[i][0] >='2' && s[i][0] <='9')
            {
                a[i] = s[i][0]-'0';
            }
            else if(s[i] == "10")    a[i] = 10;
            else if(s[i] == "A")     a[i] = 1;
            else if(s[i] == "J")     a[i] = 11;
            else if(s[i] == "Q")     a[i] = 12;
            else if(s[i] == "K")     a[i] = 13;
            else 
            {
                isexit = 1;
                break;
            }
        }
        if(isexit)
        {
            cout<<"ERROR"<<endl;
            continue;
        }
        sort(a,a+4);
        int flag = 0;
        do{
           if(is24(1,a[0],a))
           {
               flag = 1;
               break;
           }
        }while(next_permutation(a,a+4));
        
        if(flag)
        {
            for(int i = 0;i<4;i++)
            {
                switch(a[i])
                {
                    case 1:s[i] = "A";break;
                    case 2:s[i] = "2";break;
                    case 3:s[i] = "3";break;
                    case 4:s[i] = "4";break;
                    case 5:s[i] = "5";break;
                    case 6:s[i] = "6";break;
                    case 7:s[i] = "7";break;
                    case 8:s[i] = "8";break;
                    case 9:s[i] = "9";break;
                    case 10:s[i] = "10";break;
                    case 11:s[i] = "J";break;
                    case 12:s[i] = "Q";break;
                    case 13:s[i] = "K";break;
                }
            }
            cout<<s[0]<<c[0]<<s[1]<<c[1]<<s[2]<<c[2]<<s[3]<<endl;
        }
        else
            cout<<"NONE"<<endl;
    }
    return 0;
}
