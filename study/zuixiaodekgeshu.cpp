#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    while(cin >> n>>m)
    {
        if(m > n){cout<<0<<endl;continue;}
        vector<int> arr;
        for(int i = 0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            arr.push_back(tmp);
        }
        sort(arr.begin(),arr.end());
        for(int i = 0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        
        
    }
    
    
    
    return 0;
}
