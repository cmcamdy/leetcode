#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
//dp，过
class Solution
{
public:
    int knightDialer(int n)
    {
        if (n == 1)
            return 10;
        int sum = 0;
        int mod = 1e9+7;
        vector<vector<long>> dp(n, vector<long>(10, 0));
        //数组初始化
        for (int i = 0; i < 10; i++)
        {
            dp[0][i] = 1;
        }
        //1=6、8
        //2=7、9
        //3=4、8
        //4=3、9、0
        //5=不可能跳到，不用考虑
        //6=1、7、0
        //7=2、6
        //8=1、3
        //9=2、4
        //0=4、6
        for (int i = 1; i < n; i++)
        {
            dp[i][0] += (dp[i - 1][4]+dp[i - 1][6])%mod;
            dp[i][1] += (dp[i - 1][6]+dp[i - 1][8])%mod;
            dp[i][2] += (dp[i - 1][7]+dp[i - 1][9])%mod;
            dp[i][3] += (dp[i - 1][4]+dp[i - 1][8])%mod;
            dp[i][4] += (dp[i - 1][3]+dp[i - 1][9]+dp[i - 1][0])%mod;
            //5忽略
            dp[i][6] += (dp[i - 1][1]+dp[i - 1][7]+dp[i - 1][0])%mod;
            dp[i][7] += (dp[i - 1][2]+dp[i - 1][6])%mod;
            dp[i][8] += (dp[i - 1][1]+dp[i - 1][3])%mod;
            dp[i][9] += (dp[i - 1][2]+dp[i - 1][4])%mod;
        }
        for (int i = 0; i < 10; i++)
        {
            sum = (sum+dp[n - 1][i])%mod;
        }
        return sum;
    }
};