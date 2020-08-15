#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        //for(int i = 0;i<=20;i++)
           // for(int j = 0;j<=33;j++)
                //for(int k = 0;k<=300;k+=3)
                    //if(5*i+3*j+k/3 == 100 && i+j+k == 100)
                        //cout<<i<<" "<<j<<" "<<k<<endl;
        for(int i = 0;i<=14;i++)
        {
            for(int j = 0;j<=25;j++)
            {
                if(7*i+4*j == 100)
                {
                    int tmp = 100 -i - j;
                    cout<<i<<" "<<j<<" "<<tmp<<endl;
                }
            }
        }
    }
    
    
    
    
    
    
    return 0;
}
