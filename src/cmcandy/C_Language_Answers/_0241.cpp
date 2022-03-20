#include <iostream>
#include <vector>
#include <queue>
using namespace ::std;

class Solution
{
public:
    int Op(int a, int b, char op)
    {
        switch (op)
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        }
        return -1;
    }
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> val;
        vector<char> op;
        int i = 0, len = expression.size();
        while (i < len)
        {
            int s = i;
            while (i < len && isdigit(expression[i]))
                i++;
            int cur = stoi(expression.substr(s, i - s));
            val.push_back(cur);
            if (i == len)
                break;
            op.push_back(expression[i++]);
        }
        int N = val.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N));
        for (int i = 0; i < val.size(); i++)
        {
            dp[i][i] = vector<int>{val[i]};
        }
        for (int i = 1; i < val.size(); i++)
        {
            for (int j = 0; i + j < val.size(); j++)
            {
                for (int k = 0; k < i; k++)
                {
                    for (auto &a : dp[j][j + k])
                    {
                        for (auto &b : dp[j + k + 1][j + i])
                        {
                            dp[j][j + i].push_back(Op(a, b, op[j + k]));
                        }
                    }
                }
            }
        }
        return dp[0][N - 1];
    }
};
int main()
{
    Solution s;
    s.diffWaysToCompute("2-1-1");
}