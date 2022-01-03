#include <iostream>
#include <vector>
#include <string>

using namespace ::std;
class Solution
{
public:
    int minCut(string s)
    {
        // dp数组为当前字符最少需要多少次才能割成回文
        vector<int> dp(s.size(), 2000);
        dp[0] = 0;
        for (size_t i = 1; i < s.size(); i++)
        {
            if (judge(s, 0, i))
            {
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i - 1] + 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] + 1 >= dp[i])
                    continue;
                if (judge(s, j+1, i))
                    dp[i] = dp[j] + 1;
            }
        }
        return dp[s.size() - 1];
    }
    //判断回文
    bool judge(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
};
int main(){

    Solution s;
    cout<<s.minCut("cdd");

}