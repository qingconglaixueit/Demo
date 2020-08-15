#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        //保证str1是比较短的一个串
        if(str1.size()>str2.size())    swap(str1,str2);

        int start = 0;//最长公共字符串的开始位置
        int max = 0;//最长公共字串的长度
        //用短串中的字符去挨个匹配长串中的字符，如果匹配的上，则继续短串和长串往后比，同时len++
        //直到短串中的字符和长串中的字符不一样时，则，记录下最大长度
        for(int i = 0;i<str1.size();i++)
        {
            for(int j = 0;j<str2.size();j++)
            {
                if(str1[i] == str2[j])
                {
                    int tmpi = i;
                    int tmpj = j;
                    int len = 0;
                    while(str1[tmpi++] == str2[tmpj++])
                    {
                        len++;
                        if(tmpi >= str1.size() || tmpj >= str2.size())
                            break;
                    }
                    if(max < len)
                    {
                        start = i;
                        max = len;
                    }
                }
            }
        }
        cout<<max<<endl;
    }

    return 0;
}
