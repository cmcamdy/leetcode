#include <iostream>
#include <math.h>
using namespace ::std;
class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 1, right = x / 2;
        if (x < left)
            return 0;
        else if (pow(left + 1, 2) > x)
            return left;
        else if (pow(left + 2, 2) > x)
            return 2;
        while (left < right - 1)
        {
            long mid = (left + right) / 2;
            long tmpPow = pow(mid, 2);
            if (tmpPow > x)
                right = mid;
            else if (tmpPow < x)
                left = mid;
            else
                return mid;
        }
        return left;
    }
};
int main()
{
    Solution s;
    // cout<<s.mySqrt(2147395599);
    cout << s.mySqrt(5);
}