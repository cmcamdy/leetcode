#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace ::std;

class Solution
{
public:
    int stack, n;
    vector<char> path;
    vector<string> res;
    vector<string> generateParenthesis(int n)
    {
        this->n = n;
        this->stack = 0;
        vector<char> tmp(2 * n, '(');
        path = tmp;
        backtrace(0);
        return res;
    }

    void backtrace(int idx)
    {
        if (idx == 2 * n)
        {
            if (stack == 0)
            {
                string tmp;
                // vec 转 string：https://www.cnblogs.com/programer96s/p/13089435.html
                // string 转 vec 也是一样,vec也有assign函数
                tmp.assign(path.begin(), path.end());
                res.push_back(tmp);
            }
            return;
        }

        // 先（ 后 ）
        if (stack < n)
        {
            stack++;
            backtrace(idx + 1);
            stack--;
        }

        // 先 )后 (
        if (stack > 0)
        {
            path[idx] = ')';
            stack--;
            backtrace(idx + 1);
            path[idx] = '(';
            stack++;
        }
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(3);
}