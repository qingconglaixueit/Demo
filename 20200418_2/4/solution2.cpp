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
vector<vector<int>> solution::threeSum(vector<int>&nums)
{
	vector<vector<int>> vec;
	int a,b,c,d,vecsize=nums.size();
	int target = 0;
	sort(nums.begin(),nums.end());
	for(a=0;a<vecsize-3;a++)
	{
		if(a>0 && nums[a] == nums[a-1])	continue;
		for(b=a+1;b<vecsize-2;b++)
		{
			if(b>a+1 && nums[b] == nums[b-1]) continue;
			c = b+1;
			d = vecsize -1;
			while(c<d)
			{
				if(nums[a] + nums[b] + nums[c] + nums[d] == target)
				{
					vector<int> tmp;
					tmp.push_back(nums[a]);
					tmp.push_back(nums[b]);
					tmp.push_back(nums[c]);
					tmp.push_back(nums[d]);
					vec.push_back(tmp);
					tmp.clear();
					while(c<d && nums[c] == nums[c+1])	c++;
					while(c<d && nums[d] == nums[d-1])  d--;
					c++;
					d--;
				}
				else if(nums[a] + nums[b] + nums[c] + nums[d] > target)
				{
					d--;
				}
				else
				{
					c++;
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
	tmp.push_back(0);
	tmp.push_back(0);
	tmp.push_back(0);
	tmp.push_back(0);
	tmp.push_back(0);
	tmp.push_back(0);
	solution mys;
	num = mys.threeSum(tmp);
	mys.printVector(num);
	return 0;
}
