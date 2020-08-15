#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> arr;
        int tmp;
        for(int i = 0 ;i<n;i++)
        {
            cin>>tmp;
            arr.push_back(tmp);
        }
        cin >>tmp;
        for(int i = 0;i<arr.size()-1;i++)
        {
            for(int j = 0;j< arr.size()-1-i;j++)
            {
                if(tmp)
                {
                    if(arr[j+1] > arr[j])
                    {
                        int tmpnum;
                        tmpnum = arr[j+1];
                        arr[j+1] = arr[j];
                        arr[j] = tmpnum;
                    }
                }
                else
                {
                    if(arr[j+1] < arr[j])
                    {
                        int tmpnum;
                        tmpnum = arr[j+1];
                        arr[j+1] = arr[j];
                        arr[j] = tmpnum;
                    }
                }

            }
        }
        
        for(int i = 0;i<arr.size();i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    
    
    
    
    
    
    return 0;
    
}
