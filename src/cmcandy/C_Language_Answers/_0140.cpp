#include <iostream>
#include <vector>
#include <string.h>
using namespace ::std;

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        if (!wordBreak_139(s, wordDict))
            return {};

        size_t validEnd = 0;
        // 这里的dp表示的是s[0:i]这段字符串分出来的句子，如果不能分则表示为空即可，最后返回s[0:len]分出来的字符串
        vector<vector<string>> dp(s.size() + 1, vector<string>());

        for (size_t i = 0; i < s.size(); i++)
        {
            if (i == validEnd + 1)
                return {};
            if (i != 0 && dp[i].empty())
                continue;
            for (auto &word : wordDict)
            {
                size_t newEnd = i + word.size();
                if (newEnd > s.size())
                    continue;
                if (memcmp(&s[i], &word[0], word.size()) != 0)
                    continue;
                validEnd = max(validEnd, newEnd);
                if (i == 0)
                {
                    // 以0开头，newEnd结束的word需要新插入
                    dp[newEnd].push_back(word);
                    continue;
                }
                // 这里是考虑[i:newEnd]这个词，加入句子之后整个句子就扩展到[0:newEnd]这里，此时需要吧dp[i]中所有的句子添加上当前word加到dp[newENd]中
                for (auto &d : dp[i])
                {
                    dp[newEnd].push_back(d + " " + word);
                }
            }
        }
        return dp.back();
    }

    bool wordBreak_139(string s, vector<string> &wordDict)
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