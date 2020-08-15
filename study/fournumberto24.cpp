#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ret = 0;
int n = 4;

void isok(int * a,int currres,int index)
{
	if(currres == 24)
	{
		ret = 1;
		return ;
	}
	
	if(ret == 1 || currres > 24 || index > 3)
		return ;

	int i = 0;
	for(i = 0;i<n;i++)
	{
		switch(i)
		{

			case 0:
				isok(a,currres+a[index],index+1);
			break;
			case 1:
				isok(a,currres-a[index],index+1);
			break;
			case 2:
				isok(a,currres*a[index],index+1);
			break;
			case 3:
				isok(a,currres/a[index],index+1);
			break;

		}

		if(ret)
			return ;
	}

	return ;
}


int main(int argc,char * argv[])
{

	int a[4];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3])
	{
	if( (a[0]<1 || a[0] > 10) || (a[1]<1 || a[1] > 10) || (a[2]<1 || a[2] > 10) || (a[3]<1 || a[3] > 10) )
		return false;
		sort(a,a+4);
		do
		{
			cout<<1<<endl;
			isok(a,a[0],1);
		}while(next_permutation(a,a+4));
		

		if(ret)
		{
			cout<<"true"<<endl;
		}
		else
		{
			cout<<"false"<<endl;
		}
	}



	return 0;
}


