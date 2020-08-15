#include <iostream>

using namespace std;

int main()
{
    int m,n;//根据题意此处的n并无作用
    while(cin>>m>>n)
    {
        int M,N,A,B;
        cin>>M>>A;
        cout<<M<<" "<<A<<endl;
        for(int i = 1;i<m;i++)
        {
            cin>>N>>B;
            if(M == N)    continue;//如果输入的数据key重复就丢弃
            else
            {
                for(int j = 1;j<=N-M;j++)
                {
                    cout<<M+j<<" "<<A+(B-A)/(N-M)*j<<endl;
                }
                M=N;
                A=B;
            }
        }
    }

    return 0;
}
