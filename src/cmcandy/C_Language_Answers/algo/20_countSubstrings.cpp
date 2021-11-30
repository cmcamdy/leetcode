#include <iostream>
#include <string>
using namespace ::std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int slen = s.size();
        int res = 0;
        for (int i = 0; i < slen; i++)
        {
            res += countSubstringImpl(s, i, i, slen);
        }
        return res;
    }
    int countSubstringImpl(string s, int left, int right, int slen)
    {
        int count = 0;
        if (left == right)
        {
            count += countSubstringImpl(s, left, right + 1, slen);
        }
        while (left >= 0 && right < slen)
        {
            if (s[left] != s[right])
                break;
            left--;
            right++;
            count++;
        }
        return count;
    }
};

int main()
{

    Solution s;
    cout << s.countSubstrings("abc");
}