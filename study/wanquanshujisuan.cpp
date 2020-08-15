#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int res = 0;
        for(int i = 1;i<=n;i++)
        {
            int tmp = 0;
            for(int j = 1;j<=i/2;j++)
            {
                if(i % j == 0)    tmp+=j;
            }
            if(tmp == i)  
            {
                res++;
                cout<<tmp<<endl;
            }
        }
        cout<<res<<endl;
    }

    return 0;
}
