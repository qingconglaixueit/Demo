#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        for(int i = str.size()-1;i>=0;i--)
            cout<<str[i];
        cout<<endl;
        //reverse(str.begin(),str.end());
        //cout<<str<<endl;
    }
    
    return 0;
}
