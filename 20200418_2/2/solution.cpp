#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class solution{

public:
	vector<vector<int>> threeSum(vector<int>&num);

	void printVector(vector<vector<int>>tmp);

};
vector<vector<int>> solution::threeSum(vector<int>&num)
{
	vector<vector<int>> vec;
	vector<int> a;
	sort(num.begin(),num.end());
	for(int i = 0;i<num.size();i++)
	{
		for(int j = i+1;j<num.size();j++)
		{
			for(int k = j+1;k<num.size();k++)
			{
				if(num[i] + num[j] + num[k] == 0 && i!=j && i!=k && j!=k)
				{
					a.push_back(num[i]);
					a.push_back(num[j]);
					a.push_back(num[k]);
					int eq = 0;
					if(!vec.empty())
					{
						for(int p=0;p<vec.size();p++)
						{	
							if(a == vec[p])
							{
								eq = 1;
								break;
							}
						}
					}
					if(eq == 0)
					{
						vec.push_back(a);
					}
					a.clear();
				}
			}
		}
	}
	return vec;
}

void solution::printVector(vector<vector<int>>tmp)
{
	
	cout<<"["<<endl;
	for(int i = 0;i<tmp.size();i++)
	{
		cout<<"[";
		for(int j=0;j<tmp[i].size();j++)
		{
			if(j == tmp[i].size() -1)
			{
				cout<<tmp[i][j]<<"]"<<endl;
			}
			else
			{
				cout<<tmp[i][j]<<",";
			}
		}
	}
	cout<<"]"<<endl;
}
int main()
{
	vector<vector<int>>num;
	vector<int>tmp;
	tmp.push_back(-1);
	tmp.push_back(0);
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(-1);
	tmp.push_back(-4);
	solution mys;
	num = mys.threeSum(tmp);
	mys.printVector(num);
	return 0;
}
