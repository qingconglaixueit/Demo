#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseStr(string s, int k) {
        string res="";
            int i = 0;
            while(i<s.size())
            {
                if(s.size() >= 2*k || (s.size()>=k && s.size()<2*k))
                {
                    string tmp = s.substr(0,k);
                    reverse(tmp.begin(),tmp.end());
                    res = res + tmp;
                    if(s.size()<2*k)
                    {
                        res += s.substr(k);
                        s = "";
                    }
                    else
                    {
                        res += s.substr(k,k);
                        s = s.substr(2*k);
                    }

                }
                else
                {
                    reverse(s.begin(),s.end());
                    res += s;
                    s = "";
                }
            }
        return res;
    }

string reverseStr2(string s, int k) {

	for(int i = 0;i<s.size();i +=2*k)
	{
		int start = i;
		int j = min((int)(s.size()-1),start + k -1);
		if(i<j)
			reverse(s.begin()+start,s.begin()+j+1);
	}
	return s;
}
int main()
{
	string str;
	int n;
	while(cin >> str>>n)
	{
		cout << reverseStr2(str,n)<<endl;
	}




	return 0;
}
