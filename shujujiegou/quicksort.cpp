#include <iostream>
#include <time.h>

using namespace std;

void quicksort3(int *a,int left,int right)
{

	if(left >= right)	return ;
		
	int tmp = rand()%(right -left) + left;
	int k = a[tmp];
	a[tmp] = a[left];
	a[left] = k;

	int i = left;
	int j = right;
	int base = a[left];
	while(i<j)
	{
		while(i< j && a[j] >= base)	j--;
		while(i<j && a[i] <= base)  i++;
		
		if(i<j)	
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	a[left] = a[i];
	a[i] = base;
	quicksort3(a,left,i-1);
	quicksort3(a,i+1,right);

	return ;
}



void quicksort2(int *a,int left,int right)
{
	if(left >= right) return ;

	int i = left;
	int j = right;
	int base = a[i];
	
	while(i<j)
	{
		while(i<j && a[j]>=base)	j--;
		while(i<j && a[i]<=base) i++;

		if(i<j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}

	a[left] = a[i];
	a[i] = base;
	quicksort2(a,left,i-1);
	quicksort2(a,i+1,right);

}


void quicksort(int *a,int left,int right)
{

	if(left >= right)	return ;

	int i = left;
	int j = right;
	int base = a[left];
	while(i<j)
	{
		while(i< j && a[j] >= base)	j--;
		while(i<j && a[i] <= base)  i++;
		
		if(i<j)	
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	a[left] = a[i];
	a[i] = base;
	quicksort(a,left,i-1);
	quicksort(a,i+1,right);

	return ;
}


int main()
{
	srand((unsigned)time(NULL));
	int a[]={4,2,5,7,8,3,8,0,4,6,8,2,1};
	int len = sizeof(a)/a[0];
	cout<<"before quicksort()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	quicksort3(a,0,len-1);
	cout<<"after quicksort()"<<endl;
	for(int i = 0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}
