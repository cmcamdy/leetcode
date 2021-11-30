#include <iostream>
#include <vector>
#include <string>
using namespace ::std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // 滑动窗口法
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2)
            return false;
        vector<int> sum(26, 0), sum2(26, 0);
        for (int i = 0; i < len1; i++)
        {
            sum[s1[i] - 'a']++;
            sum2[s2[i] - 'a']++;
        }
        if (sum == sum2)
            return true;
        for (int i = len1; i < len2; i++)
        {
            sum2[s2[i] - 'a']++;
            sum2[s2[i - len1] - 'a']--;
            if (sum == sum2)
                return true;
        }
        return false;
    }
};