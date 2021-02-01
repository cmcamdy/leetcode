#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution
{
public:
    bool divisorGame(int N)
    {
        //N=1 必败
        //N=2 必胜
        //本题有数学证明，但个人想用动归解
        //return N%2==0;
        //dp为1维，找到<i 的false（必输局面即可获胜）若找不到，则必输
        //状态转换公式为：i % j == 0 && f[i - j] == false
        vector<bool> f(N + 1, false);
        f[1] = false;
        f[2] = true;
        for (int i = 3; i <= N; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (i % j == 0 && f[i - j] == false)
                {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[N];
    }
};