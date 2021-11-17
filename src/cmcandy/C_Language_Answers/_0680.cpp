#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution
{
public:
    bool validP(string s, int left, int right, int time)
    {
        if (time > 1)
            return false;
        while (left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                return (validP(s, left + 1, right, time + 1) || validP(s, left, right - 1, time + 1));
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int len = s.size();
        return validP(s, 0, len - 1, 0);
    }
};