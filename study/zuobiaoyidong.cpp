#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        vector<string> vec;
        int tmp = 0;
        for(int i = 0;i<str.size();i++)
        {
            if(str[i] != ';')
            {
                tmp++;
                continue;
            }
            vec.push_back(str.substr(i-tmp,tmp));
            tmp = 0;
        }
        int x = 0,y=0;
        
        for(int i = 0;i<vec.size();i++)
        {
            int num = 0;
            if(vec[i].size() == 2 && (vec[i][1] >= '0' && vec[i][1]<='9') )
                num = vec[i][1] - '0';
            else if(vec[i].size() == 3 && (vec[i][1] >= '0' && vec[i][1]<='9') && (vec[i][2] >= '0' && vec[i][2]<='9') )
                num = (vec[i][1]-'0')*10 + vec[i][2]-'0';
            
            switch(vec[i][0])
            {
                case 'A':x -= num;    break;
                case 'D':x += num;    break;
                case 'W':y += num;    break;
                case 'S':y -= num;    break;
            }
        }
        
        cout<<x<<","<<y<<endl;
    }
    
    
    
    
    
    return 0;
}
