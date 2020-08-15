#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        string res;
        int resn = 0;
        int tmpstart = 0;
        vector<int> pos;
        int tmp = 0;
        for(int i =0;i<str.size();i++)
        {
            if(str[i] >='0' && str[i]<='9')
            {
                tmp++;
                if(i == str.size() -1)
                {
                    if(resn < tmp)
                    {
                        resn = tmp;
                        pos.clear();
                        pos.push_back(tmpstart);
                    }
                    else if(resn == tmp && resn != 0)
                    {
                        pos.push_back(tmpstart);
                        tmp = 0;
                    }
                }
            }
            else
            {
                if(resn < tmp)
                {
                    resn = tmp;
                    pos.clear();
                    pos.push_back(tmpstart);
                }
                else if(resn == tmp && resn != 0)
                {
                    pos.push_back(tmpstart);
                }
                tmp = 0;
                tmpstart = i+1;
            }
        }
        
        for(int i = 0;i<pos.size();i++)
        {
            cout<<str.substr(pos[i],resn);
        }
        cout<<","<<resn<<endl;
    }

    return 0;
}
