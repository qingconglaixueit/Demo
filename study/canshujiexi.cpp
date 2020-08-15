#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        stringstream ss(str);
        string tmp="";
        int flag = 0;
        int isfirst = 0;
        vector<string> res;
        while(ss>>tmp)
        {
            if(tmp.find("\"") != -1 || flag)
            {
                if(tmp.find("\"") != -1)
                {
                    if(flag == 0)
                    {
                        isfirst = 1;
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if(flag == 1)    
                {
                    if(isfirst)
                    {
                        res.push_back(tmp+" ");
                        isfirst = 0;
                    }
                    else           res[res.size()-1] += tmp+" ";
                }
                else     res[res.size()-1] += tmp;
            }
            else    res.push_back(tmp);
        }
        cout<<res.size()<<endl;
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<endl;
    }
    
    
    
    
    return 0;
}
