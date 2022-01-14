#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace ::std;
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        unordered_map<int, int> m;
        m[arr[0]] = 0;
        int ret = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            m[arr[i]] = i;
            for (int j = 0; j < i; j++)
            {
                int temp = arr[i] - arr[j];
                if (m.count(temp) && m[temp] < j)
                {
                    dp[i][j] = dp[j][m[temp]] + 1;
                }
                else
                {
                    dp[i][j] = 2;
                }
                ret = max(ret, dp[i][j]);
            }
        }
        return ret > 2 ? ret : 0;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 44, 45, 99, 100};
    cout << s.lenLongestFibSubseq(nums);
}