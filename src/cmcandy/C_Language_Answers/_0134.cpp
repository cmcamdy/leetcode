#include <iostream>
#include <vector>

using namespace ::std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int len = gas.size();
        int remain=0;
        //先遍历一遍，找出最小值，然后，再来一遍，移动最小值为正
        int mi = INT_LEAST32_MAX, mindex = 0;

        for (int i = 0; i < len; i++)
        {
            remain = remain - cost[i] + gas[i];
            if(remain<mi){
                mi = remain;
                mindex = i;
            }
        }
        return remain>=0?(mindex+1)%len:-1;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // vector<int> gas{1,2,3,4,5};
    // vector<int> cost{3,4,5,1,2};
    // vector<int> gas{1, 2, 3, 4, 5, 5, 70};
    // vector<int> cost{2, 3, 4, 3, 9, 6, 2};
    vector<int> gas{2,3,4};
    vector<int> cost{3,4,3};
    s.canCompleteCircuit(gas, cost);
    return 0;
}
