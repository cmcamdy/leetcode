#include <iostream>
#include <string>
using namespace ::std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int len = s.size();
        int left = 0, right = len - 1;
        return validPalindromeImpl(s, left, right, 1);
    }
    bool validPalindromeImpl(string s, int left, int right, int chance)
    {
        if (chance < 0)
            return false;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return validPalindromeImpl(s, left + 1, right, chance - 1) || validPalindromeImpl(s, left, right - 1, chance - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};