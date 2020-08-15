#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> partitionLabels(string S) {
        int helper[26]={0};
        int n = S.size();
        for(int i = 0;i<n;i++)
            helper[S[i]-'a'] = i;
        vector<int> res;
        int i = 0;
        while(i<n)
        {
            int r = helper[S[i]-'a'];
            for(int j = i+1;j<r;j++)
            {
                r = max(helper[S[j]-'a'],r);
            }

            res.push_back(r-i+1);
            i = r+1;
        }
        return res;
    }

int main()
{
	string str;
	while(cin >> str)
	{
		vector<int> res = partitionLabels(str);
		cout<<"res .size == "<<res.size()<<endl;
		int index = 0;
		for(int i = 0;i<res.size();i++)
		{
			cout<<str.substr(index,res[i])<<" ";
			index += res[i];
		}
		cout<<endl;

	}

	



	return 0;
}
