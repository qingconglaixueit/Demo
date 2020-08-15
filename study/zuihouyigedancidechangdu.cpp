#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        reverse(str.begin(),str.end());
        stringstream ss(str);
        string tmp;
		ss>>tmp;
		cout<<tmp<<" == "<<tmp.size()<<endl;
    }
    
    
    
    
    return 0;
}
