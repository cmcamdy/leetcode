#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int len = triangle.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        for (int i = 2; i < len; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        int ret = INT32_MAX;
        for (int j = 0; j < len; j++)
        {
            ret = min(dp[len - 1][j], ret);
        }
        return ret;
    }
};
int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution s;
    cout<<s.minimumTotal(triangle);

}