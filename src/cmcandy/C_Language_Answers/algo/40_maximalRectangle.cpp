#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace ::std;
class Solution
{
public:
    int maximalRectangle(vector<string> &matrix)
    {
        //利用行的迭代，来转化为直方图中的最大矩形问题
        int maxArea = 0;
        int row = matrix.size();
        if (row == 0)
            return 0;
        int col = matrix[0].size();
        vector<int> heights(col + 2, 0);
        for (int i = 0; i < row; i++)
        {
            for (int j = 1; j < col + 1; j++)
            {
                if (matrix[i][j - 1] == '0')
                    heights[j] = 0;
                else
                    heights[j] += 1;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        // 单调递非减栈
        stack<int> s;
        // heights.insert(heights.begin(), 0);
        // heights.push_back(0);
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
    vector<string> matrix = {"10100", "10111", "11111", "10010"};
    Solution s;
    cout<<s.maximalRectangle(matrix);
}