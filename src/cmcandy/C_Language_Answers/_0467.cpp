#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;

class Solution
{
public:
    int findSubstringInWraproundString(string p)
    {
        vector<int> dp(26, 0);
        int len = p.size();
        if (len == 0)
            return 0;
        dp[p[0] - 'a'] = 1;
        int tmp = 1;
        int res = 0;
        //计算出以x（自变量）结尾的字符串的数字
        for (int i = 1; i < len; i++)
        {
            if ((p[i] - 'a') == (p[i - 1] + 1 - 'a') % 26)
            {
                //%26 是保证za算连续
                //连续，则连续长度++
                ++tmp;
            }
            else
            {
                //否则，则重置
                tmp = 1;
            }
            dp[p[i] - 'a'] = max(tmp, dp[p[i] - 'a']);
        }
        for (int i = 0; i < 26; i++)
        {
            res += dp[i];
        }
        return res;
    }
};