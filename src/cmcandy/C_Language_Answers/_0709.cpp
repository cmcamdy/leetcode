#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    string toLowerCase(string str)
    {
        int len = str.size();
        for (int i = 0; i < len; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
        }
        return str;
    }
};