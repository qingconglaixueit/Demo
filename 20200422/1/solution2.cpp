#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findkth(vector<int> nums1,int start1,int end1,vector<int> nums2,int start2,int end2,int k)
	{
		int len1 = end1 - start1 +1;
		int len2 = end2 - start2 +1;
		if(len1 > len2) return findkth(nums2,start2,end2,nums1,start1,end1,k);
		if(len1 == 0)  return nums2[start2 + k -1];
		int i = start1 + min(len1,k/2) -1;
		int j = start2 + min(len2,k/2) -1;
		if(nums1[i] > nums2[j])
			return findkth(nums1,start1,end1,nums2,j+1,end2,k-(j-start2 + 1));
		return findkth(nums1,i+1,end1,nums2,start2,end2,k-(i-start1 + 1));
	}
	double FindMedianSortedArrays(vector<int> & nums1,vector<int> & nums2)
	{
		int size1 = nums1.size();
		int size2 = nums2.size();
		int len = size1 + size2;
		int ktmp = (len + 1)/2;
		int k = (len + 2)/2;
		if(len % 2 == 0)
			return (findkth(nums1,0,size1-1,nums2,0,size2-1,ktmp)+findkth(nums1,0,size1-1,nums2,0,size2-1,k)) * 0.5;
		return findkth(nums1,0,size1-1,nums2,0,size2-1,ktmp);
	}
};
int main(int argc,char *argv[])
{

	vector<int> nums1;
	vector<int> nums2;
	for(int i = 1;i<2;i++)
		nums1.push_back(i);
	for(int j = 2;j<7;j++)
		nums2.push_back(j);

	Solution ll;
	cout<<ll.FindMedianSortedArrays(nums1,nums2)<<endl;
	

	
	return 0;
}
