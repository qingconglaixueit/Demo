#include <iostream>

using namespace std;
int main() {
    
    int n ,last;
    int prepos;
    int preh;
    int pos,offy;
    int res;
    while(cin >> n >> last)
    {
        res = 0;
        preh = 0;
        prepos = 0;
        for(int i = 0;i<n;i++)
        {
            cin>>pos>>offy;
            if(i == 0)
            {
                prepos = pos;
                preh = offy>0?offy:-offy;
            }
            else
            {
                res += (pos-prepos)*preh;
                //cout<<endl<<"res == "<<res;
                prepos = pos;
                int tmp = preh + offy;
                tmp = tmp>0?tmp:-tmp;
                preh = tmp;
            }
        }
        res += (last - prepos)*preh;
        cout<<res<<endl;

    }
    
}
