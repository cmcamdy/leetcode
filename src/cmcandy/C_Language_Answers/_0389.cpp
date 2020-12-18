#include <iostream>
using namespace ::std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        //计算总值即可
        int sum = 0;
        int len = s.size();

        for (int i = 0; i < len; i++)
            sum += t[i] - s[i];
        sum += t[len];
        return sum;
    }
};