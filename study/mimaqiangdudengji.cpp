#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {
        int sum = 0;
        if(str.size()<=4)    sum+=4;
        else if(str.size()>=5 && str.size()<=7)    sum +=10;
        else sum +=25;
        
        int biglet = 0;
        int smalet = 0;
        int number = 0;
        int character = 0;
        
        for(int i = 0;i<str.size();i++)
        {
            if(str[i] >='a' && str[i] <= 'z')    smalet++;
            else if(str[i] >='A' && str[i] <= 'Z') biglet++;
            else if(str[i] >='0' && str[i] <= '9') number++;
            else character++;
        }
        if(smalet > 0 && biglet > 0)    sum +=20;
        else if((smalet >0 && biglet == 0) || (biglet>0 && smalet == 0)) sum+= 10;
        
        if(number > 1 )    sum+=20;
        else if(number == 1)    sum+=10;
        
        if(character == 1)    sum+=10;
        else if(character>1)    sum+=25;
        
        if(smalet && biglet && number && character)    sum+=5;
        else if((smalet || biglet) && number && character) sum+=3;
        else if((smalet || biglet) && number)    sum+=2;
        
        if(sum>=90)    cout<<"VERY_SECURE"<<endl;
        else if(sum>=80)    cout<<"SECURE"<<endl;
        else if(sum>=70)    cout<<"VERY_STRONG"<<endl;
        else if(sum>=60)    cout<<"STRONG"<<endl;
        else if(sum>=50)    cout<<"AVERAGE"<<endl;
        else if(sum>=25)    cout<<"WEAK"<<endl;
        else     cout<<"WEAK"<<endl;
        
        
        
    }
    
    
    
    
    return 0;
}
