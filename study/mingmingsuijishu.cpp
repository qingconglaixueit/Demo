#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> v;
        for(int i = 0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        cin >> n;
        for(int i = 0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        set<int> ss;
        ss.insert(v.begin(),v.end());
        set<int>::iterator it;
        for(it = ss.begin();it!=ss.end();it++)
            cout<<*it<<endl;
    }
    
    
    
    
    
    return 0;
}




