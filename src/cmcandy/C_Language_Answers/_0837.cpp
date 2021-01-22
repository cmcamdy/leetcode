#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
//复杂度过高的dp
// class Solution {
// public:
//     double new21Game(int N, int K, int W) {
//         //0-(k-1)一个数组，记录可能性
//         //N-K表示可选范围
//         vector<float> dp(K+W,0);
//         dp[0] = 1.0;
//         for(int i = 0; i<K; i++){
//             for(int j=1;j<=W&&(i+j)<=N;j++){
//                 dp[i+j] += dp[i]/W;
//             }
//         }
//         float res = 0;
//         for(int i = K;i<=N; i++){
//             res +=dp[i];
//         }
//         return res;
//     }
// };

class Solution
{
public:
    double new21Game(int N, int K, int W)
    {
        //0-(k-1)一个数组，记录可能性
        if (K == 0)
            return 1;
        //N-K表示可选范围
        vector<float> dp(K + W + 1, 0);
        // dp[0] = 1;
        //用以记录之前算过tmp的总可能
        for (int i = K; i <= N; i++)
        {
            dp[i] = 1;
        }
        dp[K - 1] = min(N - K + 1.0, 1.0*W) / W;

        for (int i = K - 2; i >= 0; i--)
        {
            dp[i] = dp[i + 1] + (dp[i + 1] - dp[i + W+ 1]) / W;
        }
        // float res = 0;
        // for(int i = K;i<=N; i++){
        //     res +=dp[i];
        // }
        return dp[0];
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // s.new21Game(10,1,10);
    // s.new21Game(1,0,1);
    // double res = s.new21Game(6, 1, 10);
    double res = s.new21Game(21,17,10);
    return 0;
}
