#include <iostream>
#include <vector>

using namespace std;

vector<vector <int>> v_tmp;
vector<vector <int>> v_res;
vector<vector <int>> v_mig;
int n,m;

void getrute(int i,int j)
{
	v_mig[i][j] = 1;//
	v_tmp.push_back({i,j});
	
	if(i == n-1 && j == m-1)
		if(v_res.empty() || v_tmp.size() < v_res.size())	
			v_res = v_tmp;

	if(i-1 >= 0 && v_mig[i-1][j] == 0)
		getrute(i-1,j);
	if(i+1 <= n-1 && v_mig[i+1][j] == 0)
		getrute(i+1,j);
	if(j-1 >= 0 && v_mig[i][j-1]==0)
		getrute(i,j-1);
	if(j+1 <= m-1 && v_mig[i][j+1] == 0)
		getrute(i,j+1);

	v_mig[i][j] = 0;
	v_tmp.pop_back();

}

void printres()
{
	for(auto &i : v_res)
		cout<<"("<<i[0]<<","<<i[1]<<")"<<endl;
}

int main()
{
	while(cin>>n>>m)
	{
		v_mig = vector<vector<int>>(n,vector<int>(m,0));
		v_res.clear();
		v_tmp.clear();
		for(auto &i : v_mig)
			for(auto &j : i)
				cin>>j;
		getrute(0,0);
		printres();
	}





	return 0;
}
