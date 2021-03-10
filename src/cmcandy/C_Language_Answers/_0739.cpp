#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace ::std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int len = T.size();
        //用一个栈记录时间，一个栈，记录坐标，这样重复的情况就不用担心了（496也可以这么搞）
        stack<int> s;
        stack<int> index;
        vector<int> res(len, 0);

        for (int i = 0; i < len; i++)
        {
            while ((!s.empty()) && s.top() < T[i])
            {
                res[index.top()] = i - index.top();
                s.pop();
                index.pop();
            }
            s.push(T[i]);
            index.push(i);
        }
        return res;
    }
};