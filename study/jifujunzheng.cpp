#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> v;
        for(int i =0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        int number = 0;
        int total = 0,zn= 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i] < 0)    number++;
            else if(v[i] > 0)
            {
				zn++;
                total += v[i];
            }
        }
        cout<<number<<" ";
        cout<<fixed<<setprecision(1)<<(double)total/zn<<endl;
        
    }
    
    
    
    
    
    return 0;
}
