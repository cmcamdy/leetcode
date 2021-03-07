#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;
        else
            return help(n);
    }
    int help(int n)
    {
        if (n == 2)
            return 2;
        else if (n == 3)
            return 3;
        else if (n == 4)
            return 4;
        //用long接收一下边界值，然后及时mod调即可
        else
            return (long)3 * help(n - 3) % 1000000007;
    }
};