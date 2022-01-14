#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        // rgb[i] 意义为[0-i]rgb对应最小花费
        int len = costs.size();
        if (len == 1)
            return min(costs[0][0], min(costs[0][1], costs[0][2]));
        vector<int> red(len, 0);
        vector<int> green(len, 0);
        vector<int> blue(len, 0);

        red[0] = costs[0][0];
        green[0] = costs[0][1];
        blue[0] = costs[0][2];

        for (int i = 1; i < len; i++)
        {
            red[i] = min(green[i - 1], blue[i - 1]) + costs[i][0];
            green[i] = min(red[i - 1], blue[i - 1]) + costs[i][1];
            blue[i] = min(red[i - 1], green[i - 1]) + costs[i][2];
        }
        return min(red[len - 1], min(green[len - 1], blue[len - 1]));
    }
};
int main(){
    vector<vector<int>> nums = {{20,18,4},{9,9,10}};
    Solution s;
    cout<<s.minCost(nums);
}