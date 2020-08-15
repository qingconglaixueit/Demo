#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n ;
    while(cin >> n)
    {
        int a[n][2];
        string str;
        for(int i = 0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1];
        }
        cin >>str;
        
        int sum = 0,left = 0,right = 0,k = 0;
        vector<int> vec;
        for(int i = 0;i<str.size();i++)
        {
            if(str[i] !=')')
            {
                if(str[i] == '(')    left++;
                else    vec.push_back(k++);
            }
            else
            {
                right++;
                if(right > left)    break;
                int y = vec.back();
                vec.pop_back();
                int x = vec.back();
                vec.pop_back();
                sum += a[x][0] * a[x][1] * a[y][1];
                a[x][1] = a[y][1];
                vec.push_back(x);
            }
        }
        cout<<sum<<endl;
    }
    
    
    
    
    return 0;
}
