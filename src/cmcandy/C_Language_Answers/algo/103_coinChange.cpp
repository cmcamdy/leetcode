#include <iostream>
#include <vector>
#include <string>
using namespace ::std;

// 我用的是二维DP
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // dp[i][j] 表示 前i个coin中凑够j所用的最小硬币数，不能就记为-1
        int len = coins.size();
        if (amount == 0)
            return 0;

        vector<vector<int>> dp(len, vector<int>(amount + 1, -1));
        for (int i = 0; i < len; i++)
        {
            dp[i][0] = 0;
        }
        int tmp = coins[0];
        for (int j = coins[0]; j <= amount; j++)
        {
            if (dp[0][j - coins[0]] != -1)
                dp[0][j] = dp[0][j - coins[0]] + 1;
        }
        for (int i = 1; i < len; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i] && dp[i][j - coins[i]] != -1)
                    if (dp[i][j] == -1)
                    {
                        dp[i][j] = dp[i][j - coins[i]] + 1;
                    }
                    else
                    {
                        dp[i][j] = min(dp[i][j - coins[i]] + 1, dp[i][j]);
                    }
            }
        }
        return dp[len - 1][amount];
    }
};
// 官方用的是一维DP
class Solution2
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < (int)coins.size(); ++j)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main()
{
    Solution s;
    // vector<int> coins = {1};
    // cout << s.coinChange(coins, 2);
    // vector<int> coins = {1, 2, 5};
    // cout << s.coinChange(coins, 11);
    vector<int> coins = {2, 5, 10, 1};
    cout << s.coinChange(coins, 27);
}