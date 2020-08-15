#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findclose(vector<string> & vec,string word1,string word2)
{
	int w1 = -1, w2 = -1;
	int res = vec.size();
	for(int i = 0;i<vec.size();i++)
	{
		if(vec[i] == word1)	w1 = i;
		else if(vec[i] == word2) w2 = i;
		if(w1 != -1 && w2 != -1) res = min(res,abs(w1-w2));
		if(res == 1) break;
	}
	return res;
}

int main()
{
	vector<string> vec = {"I","am","a","student","from","a","university","in","a","city"};
	string word1,word2;
	while(cin>>word1>>word2)
	{
		cout<<findclose(vec,word1,word2)<<endl;
	}

	return 0;
}
