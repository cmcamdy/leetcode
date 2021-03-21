#include <iostream>
#include <vector>

using namespace ::std;
class Solution
{
public:
    int numSquares(int n)
    {
        if (n < 4)
            return n;
        vector<int> dp(n + 1, 0);
        //初始化为最坏的情况
        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;
        }
        vector<int> sqnum(n, 0);
        //初始化平方数
        int k = 1;
        while (sqnum[k - 1] <= n)
        {
            sqnum[k] = k * k;
            k++;
        }

        for (int i = 4; i <= n; i++)
        {
            k = 1;
            while (sqnum[k] <= i)
            {
                dp[i] = min(dp[i - sqnum[k++]] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    s.numSquares(4);
    return 0;
}
