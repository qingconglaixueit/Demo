#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> v;
    while(cin >> n)
    {
        int tmp;
        for(int i = 0;i<n;i++)
        {
            cin>>tmp;
            v.push_back(tmp);
        }
        int m;
        cin>>m;
        for(int i = 0;i<m;i++)
        {
            cin>>tmp;
            v.push_back(tmp);
        }
        
        set<int> s;
        s.insert(v.begin(),v.end());
        for(auto a:s)
            cout<<a;
		cout<<endl;
		v.clear();
        
    }
    
    
    
    
    
    return 0;
}
