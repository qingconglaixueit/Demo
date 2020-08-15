#include <iostream>

using namespace std;

int main()
{
   // int n;
   // int arr[100]={0};
   // arr[1] = 1;
   // arr[2] = 1;
   /// arr[3] = 2;
   // for(int i = 4;i<100;i++)
   //     arr[i] = arr[i-1] + arr[i-2];
    //while(cin >> n)
    //    cout<<arr[n]<<endl;
    
    
    int n;
    while(cin>>n)
    {
        int shu1 = 1;
        int shu2 = 0;
        int shu3 = 0;
        while(--n)
        {
            shu3 +=shu2;
            shu2 = shu1;
            shu1 = shu3;
        }
        cout<<shu1+shu2+shu3<<endl;
    }

    
    
    
    
    
    
    
    return 0;
}
