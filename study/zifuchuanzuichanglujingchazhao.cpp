#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        multiset<string> ss;
        string tmp;
        for(int i = 0;i<n ;i++)
        {
            cin >> tmp;
            ss.insert(tmp);
        }
		
        
        for(multiset<string>::iterator it = ss.begin();it!=ss.end();it++)
            cout<<*it<<endl;
    }

    return 0;
}
