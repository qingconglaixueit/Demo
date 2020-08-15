#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
 		
	int j = 0;
	if(nums .empty()) return 0;
	for(int i = 1;i<nums.size();i++)	
	{
		if(nums[j] != nums[i])
		{
			j++;
			nums[j] = nums[i];
		}
	}
   	return j+1;
}

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> a;
		for(int i = 0;i<n;i++)
		{
			int tmp;
			cin>>tmp;
			a.push_back(tmp);
		}
		int res = removeDuplicates(a);
		cout<<res<<endl;	
		for(int i = 0;i<a.size();i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}

	return 0;
}
