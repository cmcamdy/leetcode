#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace ::std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> s;
        int len = temperatures.size();
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++)
        {
            if (s.empty())
                s.push(i);
            else if (temperatures[s.top()] >= temperatures[i])
            {
                s.push(i);
            }
            else
            {
                //开始填
                while (!s.empty() && temperatures[s.top()] < temperatures[i])
                {
                    res[s.top()] = i - s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        return res;
    }
};