#include <iostream>
#include <vector>
#include <string>
using namespace ::std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // 滑动窗口法
        int len1 = p.size(), len2 = s.size();
        vector<int> res;
        if (len1 > len2)
            return res;
        vector<int> sum(26, 0), sum2(26, 0);
        for (int i = 0; i < len1; i++)
        {
            sum[p[i] - 'a']++;
            sum2[s[i] - 'a']++;
        }
        if (sum == sum2)
            res.push_back(0);
        for (int i = len1; i < len2; i++)
        {
            sum2[s[i] - 'a']++;
            sum2[s[i - len1] - 'a']--;
            if (sum == sum2)
                res.push_back(i - len1 + 1);
        }
        return res;
    }
};