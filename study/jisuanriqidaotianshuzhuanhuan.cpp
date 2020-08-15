#include <iostream>

using namespace std;

int main()
{
    int days[12]    ={31,28,31,30,31,30,31,31,30,31,30,31};
    int year,month,day,res = 0;
    while(cin>>year>>month>>day)
    {
        int flag = 0;
        if(year % 400 == 0 || (year % 100 !=0 && year % 4 == 0) )
            flag = 1;
        res+=flag;
        for(int i =0;i<month-1;i++)
        {
            res += days[i];
        }
        res+=day;
        cout<<res<<endl;
        
    }
    
    
    
    return 0;
}
