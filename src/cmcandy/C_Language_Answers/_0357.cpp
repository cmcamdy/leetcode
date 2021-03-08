#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        else if (n == 1)
            return 10;
        else if (n == 2)
            return 91;
        else if (n > 10)
            return countNumbersWithUniqueDigits(10);
        else
        {
            return countNumbersWithUniqueDigits(n - 1) + 9*A(9, n - 1);
        }
    }
    int A(int m, int n)
    {
        //排列组合计算
        if (n == 1)
            return m;
        else
            return m * A(m - 1, n - 1);
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    s.countNumbersWithUniqueDigits(3);
    return 0;
}
