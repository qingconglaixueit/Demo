#include <iostream>
#include <string>

using namespace std;

const string gewei[]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const string shiji[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nighteen" };
const string jishi[]={"zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
const string hundreds[]={"hundred", "thousand", "million", "billion" };
const int inthundreds[]={(int)1e2, (int)1e3, (int)1e6, (int)1e9, (int)1e12 };

string itostr(long n)
{
    if(n >= 0 && n<10)    return gewei[n];
    if(n>=10 && n<20)     return shiji[n%10];
    if(n>=20 && n<100)    return jishi[n/10] + (n%10? " " +gewei[n%10]:"" );
    for(int i = 0;i<4;i++)
    {
        if(n<inthundreds[i+1])
        {
            return itostr(n/inthundreds[i])+" "+hundreds[i] + (n%inthundreds[i] ? (i?" ":" and ")+itostr(n%inthundreds[i]) : "");
        }   
    }
    return "";
}

int main()
{
    long n;
    while(cin>>n)
    {
        cout<<itostr(n)<<endl;;
    }
    
    
    
    
    
    
    
    return 0;
}
