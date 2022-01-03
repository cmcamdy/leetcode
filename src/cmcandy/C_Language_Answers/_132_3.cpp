#include <iostream>
#include <vector>
#include <string>

using namespace ::std;
class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<int>> g(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
            }
        }

        vector<int> f(n, 2000);
        for (int i = 0; i < n; ++i)
        {
            if (g[0][i])
            {
                f[i] = 0;
            }
            else
            {
                for (int j = 0; j < i; ++j)
                {
                    if (g[j + 1][i])
                    {
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }

        return f[n - 1];
    }
};
