#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        int flag[4] = {0};
        if(str.size()<8){
            cout<<"NG"<<endl;
            continue;
        }
        
        for(int i = 0;i<str.size();i++)
        {
            if(str[i] >= '0' && str[i] <= '9')    flag[0] = 1;
            else if(str[i] >= 'a' && str[i] <= 'z')    flag[1] = 1;
            else if(str[i] >= 'A' && str[i] <= 'Z')    flag[2] = 1;
            else    flag[3] = 1;
        }
        if(flag[0] + flag[1] + flag[2] + flag[3] < 3){
            cout<<"NG"<<endl;
            continue;
        }
        bool resflag = true;
        for(int i = 0;i<str.size()-6;i++)
        {
            for(int j=i+3;j<str.size();j++)
            {
                if(str[i] == str[j] && str[i+1] == str[j+1] && str[i+2] == str[j+2])
                {
                    resflag = false;
                    break;
                }
            }
        }
        if(resflag)     cout<<"OK"<<endl;
        else            cout<<"NG"<<endl;
    }
    
    
    
    
    return 0;
}
