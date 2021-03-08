#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        //关键是恰好，因此考虑n的因数
        int i = 2;
        while (i < n)
        {
            //找到因数，直接复制黏贴即可
            if (n % i == 0)
                return i + minSteps(n / i);
            i++;
        }
        return n;
    }
};