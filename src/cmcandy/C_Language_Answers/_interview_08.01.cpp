#include <iostream>
#include <vector>
using namespace ::std;

class Solution
{
public:
    int waysToStep(int n)
    {
        //可能存在int不够用的情况
        if (n == 0)
            return 0;
        vector<long> dp(n + 2, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        long tmp;

        for (int i = 3; i < n + 1; i++)
        {
            tmp = dp[i - 1] + dp[i - 2] + dp[i - 3];
            dp[i] = tmp >= 1000000007 ? tmp % 1000000007 : tmp;
        }

        return dp[n] % 1000000007;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.waysToStep(80);
    return 0;
}
