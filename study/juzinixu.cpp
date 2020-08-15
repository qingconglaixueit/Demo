#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
#if 0
    string str;
    while(getline(cin,str))
    {
        string tmp;
        int start = 0;
        string res;
        int i =0;
        for(i =0;i<str.size();i++)
        {
            if(str[i] == ' ')
            {
                tmp = str.substr(start,i-start);
                reverse(tmp.begin(),tmp.end());
                res.append(tmp);
                tmp.clear();
                res.append(" ");
                start = i+1;
            }
        }
        tmp = str.substr(start,i-start);
        reverse(tmp.begin(),tmp.end());
        res.append(tmp);

		reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
#endif
 	

	string str;
	while(getline(cin,str))
	{
		stringstream ss(str);
		string tmp,res="";
		while(ss>>tmp)
		{
			if(res == "")
				res = tmp;
			else
			res = tmp+" "+res;
		}

		cout<<res<<endl;
	}


































   

    return 0;
}
