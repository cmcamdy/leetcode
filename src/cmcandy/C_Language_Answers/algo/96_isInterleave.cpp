#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        // 边界情况
        if (len1 + len2 != len3)
            return false;
        else if (len1==0) return s2==s3;
        else if (len2==0) return s1==s3;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // init
        dp[0][0] = 0;
        dp[0][1] = s2[0]==s3[0];
        dp[1][0] = s1[0]==s3[0];
        for (int i = 2; i < len1 + 1; i++)
        {
            dp[i][0] = (dp[i - 1][0] == 1 && s1[i - 1] == s3[i - 1]) ? 1 : 0;
        }
        for (int j = 2; j < len2 + 1; j++)
        {
            dp[0][j] = (dp[0][j - 1] == 1 && s2[j - 1] == s3[j - 1]) ? 1 : 0;
        }

        for (int i = 1; i < len1 + 1; i++)
        {
            for (int j = 1; j < len2 + 1; j++)
            {   
                // 这里是递推式
                dp[i][j] = ((dp[i][j - 1] == 1 && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] == 1 && s1[i - 1] == s3[i + j - 1])) ? 1 : 0;
            }
        }
        return dp[len1][len2];
    }
};
int main()
{
    Solution s;
    // cout<<s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    // cout<<s.isInterleave("a", "", "a");
    cout<<s.isInterleave("aa", "ab", "abaa");
}