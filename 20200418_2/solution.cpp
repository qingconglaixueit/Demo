#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class solution{

public:
	vector<int> twoSum(vector<int>&num,int target);

	void printVector(vector<int>tmp);

};
vector<int> solution::twoSum(vector<int>&num,int target)
{
	vector<int>tmp;
	for(int i = 0;i<num.size();i++)
	{
		for(int j=i+1;j<num.size();j++)
		{
			if(num[i] + num[j] == target && i!=j)
			{
				tmp.push_back(i);
				tmp.push_back(j);
			}
		}
	}
	return tmp;
}

void solution::printVector(vector<int>tmp)
{
	
	cout<<"[";
	for(int i = 0;i<tmp.size();i++)
	{
		cout<<tmp[i];
		if(i == tmp.size()-1)
		{
			cout<<"]"<<endl;
		}
		else
		{
			cout<<",";
		}
	}
}
int main()
{
	vector<int>num;
	vector<int>tmp;
	tmp.push_back(2);
	tmp.push_back(7);
	tmp.push_back(11);
	tmp.push_back(13);
	solution mys;
	num = mys.twoSum(tmp,9);
	mys.printVector(num);
	return 0;
}
