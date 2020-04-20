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
	int vecsize = nums.size();
	if(vecsize <= 2)//不满足于三个数的时候
	{
		return vec;
	}
	int usesize = vecsize -2;//三个数求时，只需要循环n-2次
	sort(nums.begin(),nums.end());
	for(int i = 0;i<usesize;i++)
	{
		int target = 0 - nums[i];
		if(nums[i] > 0)//因为数组已经排序，若固定的这个数都大于0，那么后面的数只会更大
		{
			break;
		}
		int l = i+1;
		int r = vecsize -1;
		if(i == 0 || (i>0 && nums[i] != nums[i-1])) //存在惰性运算
		{
			while(l < r)
			{
				if(nums[l] + nums[r] == target)
				{
					int prenum = nums[l];
		  			vector<int>tmp;
					tmp.push_back(nums[i]);
					tmp.push_back(nums[l]);
					tmp.push_back(nums[r]);
					sort(tmp.begin(),tmp.end());
					vec.push_back(tmp);
					tmp.clear();
					while(nums[l+1] == nums[l] &&  l < r)
					{
						l++;
					}
				}
				else if(nums[l] + nums[r] >  target)
				{
					r--;
				}
				else
				{
					l++;
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
