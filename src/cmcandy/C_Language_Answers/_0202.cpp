#include <map>
#include <iostream>
using namespace ::std;
class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        //map 记录一下
        map<int, int> m;
        m[n] = 1;
        int sum = 0;
        int tmp = 0;
        while (sum != 1)
        {
            while (n != 0)
            {
                tmp = n % 10;
                n = n / 10;
                sum += tmp * tmp;
            }
            if (m[sum] == 1)
                return false;
            else if (sum != 1)
            {
                n = sum;
                m[sum] = 1;
                sum = 0;
            }
        }
        return true;
    }
};