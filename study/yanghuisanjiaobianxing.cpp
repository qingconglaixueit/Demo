#include <iostream>

using namespace std;

int main()
{

    int n;
    while(cin>>n)
    {
        if(n <= 2)
            cout<<-1<<endl;
        else if((n-2) % 4 == 0)
            cout<<4<<endl;
        else if(n % 2 == 1)
            cout<<2<<endl;
        else
            cout<<3<<endl;
    }
}
