#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num;
    while (cin >> num)
    {
        int temp, max = 1;
        vector<int> ivec, add;
        while (num-- && cin >> temp) //填充
            ivec.push_back(temp);
        for (size_t i = 0; i < ivec.size(); ++i)//动态规划，附加数组
        {
            add.push_back(1);
            for (size_t j = 0; j < i; j++)
                if (ivec[i]>ivec[j] && add[j] + 1 > add[i])//add[j] + 1 > add[i]必须加上，不知道为什么
                    add[i] = add[j] + 1;
            if (max < add[i])
                max = add[i];
        }
        cout << max << endl;
    }
    return 0;
}
