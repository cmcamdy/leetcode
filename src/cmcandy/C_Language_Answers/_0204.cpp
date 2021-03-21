
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace ::std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1 || n == 2)
            return 0;
        vector<int> dp = vector<int>(n, 1);
        dp[0] = 0;
        dp[1] = 0;
        int sum = 0;
        for (int i = 2; i < n; i++)
        {
            if (dp[i] == 0)
                continue;
            else
            {
                sum++;
                int j = i + i;
                while (j < n)
                {
                    dp[j] = 0;
                    j += i;
                }
            }
        }

        return sum;
    }
};