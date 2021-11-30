#include <iostream>
#include <map>
#include <string>
using namespace ::std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int slen = s.size(), tlen = t.size();
        if (slen < tlen)
            return "";
        if (slen == 1 && tlen == 1)
            return s == t ? s : "";
        map<char, int> m;
        int left = 0, right = 0;
        int count = 0, mlen = 100000, start = 0;
        for (int i = 0; i < tlen; i++)
        {
            if (m.find(t[i]) == m.end())
            {
                m[t[i]] = 1;
                count++;
            }
            else
                m[t[i]] += 1;
        }

        for (; right < slen; right++)
        {
            if (m.find(s[right]) != m.end())
            {
                m[s[right]]--;
                if (m[s[right]] == 0)
                    count--;
            }
            while (count == 0)
            {
                //说明满足条件了
                if (mlen > right - left + 1)
                {
                    mlen = right - left + 1;
                    start = left;
                }
                if (m.find(s[left]) != m.end())
                {
                    m[s[left]]++;
                    if (m[s[left]] > 0)
                        count++;
                }
                left++;
            }
        }
        return mlen == 100000 ? "" : s.substr(start, mlen);
    }
};
int main()
{

    Solution s;
    s.minWindow("ab", "A");
}