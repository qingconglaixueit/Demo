#include <iostream>
#include <string.h>

using namespace std;

void mergearr(int *a,int b1,int e1,int b2,int e2,int *tmp)
{
	int index = b1;
	int i = b1,j = b2;
	while(i<=e1 && j<= e2)//会有b1 == e1, b2 == e2的情况
	{
		if(a[i]<=a[j]) tmp[index++] = a[i++];
		else	tmp[index++] = a[j++];
	}
	
	while(i<= e1)//判断之前是否是因为i跳出上面代码的循环
		 tmp[index++] = a[i++];

	while(j<=e2)//判断之前是否是因为j跳出上面代码的循环
		tmp[index++] = a[j++];

	memcpy(a+b1,tmp+b1,sizeof(int) * (e2 - b1 + 1));//将数据拷贝到源数组a的原位置
	return ;
}

void mergesort(int *a ,int left,int right,int *tmp)
{
	if(a == NULL)	return ;
	if(left >= right) return ;
	
	int mid = left+(right + left)/2;//分成2半
	
	mergesort(a,left,mid,tmp);//左边继续递归
	
	mergesort(a,mid+1,right,tmp);//右边继续递归

	mergearr(a,left,mid,mid+1,right,tmp);//合并左右序列

	return ;	
}

int main()
{
	int a[]={4,2,5,7,8,3,8,0,4,6,8,2,1};
	int len = sizeof(a)/a[0];
	int * tmp = (int *)malloc(len * sizeof(int));
	memset(tmp,-1,len);
	cout<<"before mergesort()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	mergesort(a ,0,len-1,tmp);
	cout<<"after mergesort()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}
