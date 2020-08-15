/**
数学家斐波那契提出的一种求解***分数的贪心算法，准确的算法表述应该是这样的：
设某个真分数的分子为a，分母为b;
把c=(b/a+1)作为分解式中第一个***分数的分母；
将a-b%a作为新的a；
将b*c作为新的b；
如果a等于1，则最后一个***分数为1/b,算法结束；
如果a大于1但是a能整除b，则最后一个***分数为1/(b/a),算法结束；
否则重复上面的步骤。
**/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a,b;
    char ch;
    while(cin>>a>>ch>>b)
    {
        while(a != 1)
        {
            if(b%(a-1) == 0)
            {
                cout<<1<<"/"<<b/(a-1)<<"+";
                a=1;
            }else
            {
                int c = b/a +1;
                cout<<1<<"/"<<c<<"+";
                a = a - b%a;
                b= b*c;
                if(b%a == 0)
                {
                    b = b/a;
                    a= 1;
                }
            }
        }
        cout<<1<<"/"<<b<<endl;
    }

    return 0;
}
