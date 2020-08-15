#include <iostream>
#include <string>
#include <vector>

using namespace std;


int totalFruit(vector<int>& tree) {
	int n = tree.size();
	if(n <= 2)	return n;

	int left = 0;
	int index1 = 0;
	int type1 = tree[left];
	while(index1 < n && tree[index1] == type1)	index1++;
	if(index1 == n)	return index1;
	int index2  = index1;
	index1 --;
	int type2 = tree[index2];
	int res = -1;
	int right = index2;
	while(right < n)
	{
		if(tree[right] == type1)
		{
			index1 = right;
			right++;
		}
		else if(tree[right] == type2)
		{
			index2 = right;
			right++;
		}
		else
		{
			res = max(res,right-left);
			if(tree[right-1] == type1)
			{
				left = index2+1;
			}
			else
			{
				type1= type2;
				left = index1+1;
				index1 = index2;
			}
			type2 = tree[right];
			index2 = right;
		}
	}
	res = max(res,right-left);
	return res;
}

int main()
{
	vector<int> tree ={1,0,1,4,1,4,1,2,3};
	cout<<totalFruit(tree)<<endl; 
	return 0;
}
