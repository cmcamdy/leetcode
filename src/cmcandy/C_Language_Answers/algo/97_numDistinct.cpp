#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int len1 = s.size(), len2 = t.size();
        if (len1 < len2)
            return 0;
        vector<vector<unsigned int>> dp(len2, vector<unsigned int>(len1, 0));
        // vector<vector<long>> dp(len2,vector<long>(len1,0));
        dp[0][0] = s[0] == t[0];
        for (int j = 1; j < len1; j++)
        {
            dp[0][j] = dp[0][j - 1] + (s[j] == t[0]);
        }
        for (int i = 1; i < len2; i++)
        {
            for (int j = i; j < len1; j++)
            {
                dp[i][j] = dp[i][j - 1] + (s[j] == t[i] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[len2 - 1][len1 - 1];
    }
};