#include <iostream>
#include <vector>
#include <string.h>
using namespace ::std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        size_t validEnd = 0;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (i == validEnd + 1)
                return false;
            if (!dp[i])
                continue;
            for (auto &word : wordDict)
            {
                size_t newEnd = i + word.size();
                if (newEnd > s.size())
                    continue;
                if (memcmp(&s[i], &word[0], word.size()) == 0)
                {
                    dp[newEnd] = true;
                    validEnd = max(validEnd, newEnd);
                }
            }
        }
        return dp.back();
    }
};