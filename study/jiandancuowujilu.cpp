#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    int n;
    int i = 0;
    string file[8];
    int number[8]={0};
    int error[8]={0};
    int res = 0;
    while(cin>>str>>n)
    {
        int index = str.find_last_of("\\");
        string tmp = str.substr(index+1);
        if(tmp.size() > 16)
            tmp = tmp.substr(tmp.size()-16);
        
        file[i] = tmp;
        number[i] = n;
        error[i]++;
        res++;
        if(i == 7)    i = 0;
        else          i++;
    }
    for(int i = 0;i<8;i++)
    {
        cout<<file[i]<<" "<<number[i]<<" "<<error[i]<<endl;
    }
    
    
    
    return 0;
}
