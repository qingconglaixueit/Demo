#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int num;
    int fn = 0;
    int res = 0,resn = 0;
    while(cin>>num)
    {
        if(num < 0)
        {
            fn++;
        }else
        {
            resn++;
            res+=num;
        }
    }
    cout<<fn<<endl;
    cout<<fixed<<setprecision(1)<<(double)res/resn<<endl;
    
    
    return 0;
}
