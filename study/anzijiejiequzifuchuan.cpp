#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int num;
        cin>>num;
        cout<<str.substr(0,num)<<endl;
    }
    
    
    
    
    
    return 0;
}
