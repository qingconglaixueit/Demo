#include <iostream>
#include <vector>

using namespace std;

int numSubarraysWithSum(vector<int>& A, int S) 
{
        int res = 0;
        for(int i = 0;i<A.size();i++)
        {
            if(A[i] == S)   res++;
            int j = i+1;
            while(j<A.size())
            {
                int tmp = 0;
                int k = i;
                while(k<=j)
                {
                    tmp +=A[k];
                    k++;
                }
                if(tmp == S)    res++;

                j++;
            }
        }
        return res;
}

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> a;
		int tmp;
		for(int i = 0;i<n;i++)
		{
			cin>>tmp;
			a.push_back(tmp);
		}
		cin>>tmp;
		cout<<numSubarraysWithSum(a,tmp)<<endl;
		
	}

	return 0;
}
