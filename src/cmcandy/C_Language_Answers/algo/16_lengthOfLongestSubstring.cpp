#include <iostream>
#include <map>
#include <string>
using namespace ::std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.size();
        if (len <= 1)
            return len;
        map<char, int> m;
        int left = 0, right = 0, mlen = 0;
        for (right = 0; right < len; right++)
        {
            if (m.find(s[right]) == m.end())
            {
                m[s[right]] = 1;
            }
            else
            {
                while (m[s[right]] > 0)
                {
                    m[s[left++]]--;
                }
                m[s[right]]++;
            }
            mlen = max(right - left + 1, mlen);
        }
        return mlen;
    }
};