#include <iostream>
#include <vector>
#include <stack>
using namespace ::std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // 单调递非减栈
        stack<int> s;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int len = heights.size();
        int maxArea = heights[0];
        s.push(0);
        for (int i = 1; i < len; i++)
        {
            while (heights[i] < heights[s.top()])
            {
                int tmp = s.top();
                s.pop();
                maxArea = max(maxArea, heights[tmp] * (i - s.top() - 1));
            }
            s.push(i);
        }
        return maxArea;
    }
};
int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution s;
    cout << s.largestRectangleArea(heights);
}