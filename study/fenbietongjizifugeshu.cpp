#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    
    while(getline(cin,str))
    {
        int n=0,m=0,j=0,k=0;
        for(int i = 0;i<str.size();i++)
        {
            if((str[i] >='a' && str[i] <='z') || (str[i] >='A' && str[i] <='Z') )
             n++;
            else if(str[i] == ' ')
             m++;
            else if(str[i] >='0' && str[i] <='9')
             j++;
            else
               k++;
        }
        cout<<n<<endl<<m<<endl<<j<<endl<<k<<endl;
    }
    
    
    
    
    
    return 0;
}
