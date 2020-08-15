#include <iostream>
#include <string>

using namespace std;

int main()
{
    unsigned int a,b,c,d,num;
    char ch;
    while(cin>>a>>ch>>b>>ch>>c>>ch>>d>>num)
    {
        cout<<(a<<24 | b<< 16 | c << 8 | d)<<endl;
       cout<<((num & 0xff000000)>>24)<<"."<<((num & 0x00ff0000)>>16)<<"."<<((num & 0x0000ff00)>>8)<<"."<<(num & 0x000000ff)<<endl;
		//cout<<((num&0xff000000)>>24)<<"."<<((num & 0x00ff0000)>>16)<<"."<<((num&0x0000ff00)>>8)<<"."<<(num & 0x000000ff)<<endl;
    }
    
    
    
    
    
    
    return 0;
}
