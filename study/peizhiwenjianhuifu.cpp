#include <iostream>
#include <string>
#include <sstream>

using namespace std;
bool match(string str,string s)
{
    return str.find(s) == 0;
}
int main()
{
    string cmd[6] = {"reset",       "reset board", "board add",     "board delet",      "reboot backplane", "backplane abort" };
    string res[7] = {"reset what",  "board fault", "where to add",  "no board at all",  "impossible",       "install first",    "unknown command" };
    string str;
    while (getline(cin, str)) {
        string s1,s2;
        int resi = 6;
        stringstream ss(str);
        ss>>s1>>s2;
        if(s2.empty())
            resi = match(cmd[0],s1)?0:6;
        else
        {
            int flag = 0;
            for(int i = 1;i<6;i++)
            {
                string tmp1,tmp2;
                stringstream ss(cmd[i]);
                ss>>tmp1>>tmp2;
                if(match(tmp1,s1) && match(tmp2,s2))
                {
                    if(flag == 0)
                    {
                        flag = 1;
                        resi = i;
                    }else
                    {
                        resi = 6;
                    }
                }
            }
        }
        cout<<res[resi]<<endl;
    }
    return 0;
}
