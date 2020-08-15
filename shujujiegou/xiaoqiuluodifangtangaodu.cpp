#include <iostream>

using namespace std;

int main()
{
    int height;
    while(cin >> height)
    {
        double res = height;
        int tmp = 2;
        for(int i = 1;i<=4;i++)
        {
            res += ((double)height/tmp)*2;
            cout<<"res == "<<res<<"------"<<(double)height/tmp<<endl;
            tmp = tmp*2;
        }
        res += ((double)height/tmp);
        cout<<res<<endl<<(double)height/32<<endl;
    }
    
    
    
    
    return 0;
}
