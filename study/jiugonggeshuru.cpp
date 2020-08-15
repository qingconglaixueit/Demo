#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        if(str[0] != '#')//数字模式
        {
            for(int i =0;i<str.size();i++)
            {
                if(str[i] >='0' && str[i] <='9')
                {
                    cout<<str[i];
                }
            }
            cout<<endl;
        }
        else//英文模式
        {
            string res;
            string helper[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
            int prenum = 0;
            int tmp = 0;
            for(int i = 1;i<str.size();i++)
            {
                if(i == 1&& (str[i]>='0' && str[i]<='9') )
                {
                    prenum = str[i]-'0';
                    tmp++;
                }
                else
                {
                    if(prenum == str[i]-'0')
                    {
                        tmp++;
                    }
                    else
                    {
                        int index;//数字对应字符第一个索引
                        switch(prenum)
                        {
                            case 2:     index = (tmp%3)?(tmp%3)-1:2;break;
                            case 3:     index = (tmp%3)?(tmp%3)-1+3:5;break;
                            case 4:     index = (tmp%3)?(tmp%3)-1+6:8;break;
                            case 5:     index = (tmp%3)?(tmp%3)-1+9:11;break;
                            case 6:     index = (tmp%3)?(tmp%3)-1+12:14;break;
                            case 7:     index = (tmp%4)?(tmp%4)-1+15:18;break;
                            case 8:     index = (tmp%3)?(tmp%3)-1+19:21;break;
                            case 9:     index = (tmp%4)?(tmp%4)-1+22:25;break;
                        }
                         //cout<<"---tmp ----"<<tmp<<endl;
                        //cout<<"---index ----"<<tmp<<endl;
                        res += helper[index];
                        //cout<<"---res ----"<<res<<endl;
                        if(str[i]>='0' && str[i]<='9')
                        {
                            tmp =1;
                            prenum = str[i] -'0';
                           // cout<<"======i == "<<i<<endl;
                        }
                        else
                        {
                            if(i+1 < str.size())
                            {
                                prenum = str[i+1] - '0';
                                i++;
                                tmp = 1;
                            }
                        } 
                    }
                }
            }
            int index;//数字对应字符第一个索引
             switch(prenum)
             {
                case 2:     index = (tmp%3)?(tmp%3)-1:2;break;
                case 3:     index = (tmp%3)?(tmp%3)-1+3:5;break;
                case 4:     index = (tmp%3)?(tmp%3)-1+6:8;break;
                case 5:     index = (tmp%3)?(tmp%3)-1+9:11;break;
                case 6:     index = (tmp%3)?(tmp%3)-1+12:14;break;
                case 7:     index = (tmp%4)?(tmp%4)-1+15:18;break;
                case 8:     index = (tmp%3)?(tmp%3)-1+19:21;break;
                case 9:     index = (tmp%4)?(tmp%4)-1+22:25;break;
             }
            res += helper[index];
            cout<<res<<endl;
        } 
    }
    
    
    
    
    return 0;
}
