#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric> // std::iota
using namespace ::std;

class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        // 播种的总时间是不变的，因此我们需要得到的是成长时间最短放在最后面，之前的只需要不超过这个数就好了
        vector<int> id(plantTime.size(), 0);
        // iota是顺序赋值，用来重排下标
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j)
             { return growTime[i] > growTime[j]; });
        int ans = 0, day = 0;
        for (int i : id)
        {
            day += plantTime[i];
            ans = max(ans, day + growTime[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    //     [15,29,24,8,14,26,12,15,27,2,5,10,7,17,9,5,9,21,11,13,13,2,1,17,11]
    // [26,20,10,9,8,27,1,19,13,22,10,10,21,14,17,14,17,30,3,3,14,16,7,12,25]

    // vector<int> plant = {15,29,24,8,14,26,12,15,27,2,5,10,7,17,9,5,9,21,11,13,13,2,1,17,11};
    // vector<int> grow = {26,20,10,9,8,27,1,19,13,22,10,10,21,14,17,14,17,30,3,3,14,16,7,12,25};

    // vector<int> plant = {1,4,3};
    // vector<int> grow = {2,3,1};
    vector<int> plant = {1, 2, 3, 2};
    vector<int> grow = {2, 1, 2, 1};
    cout << s.earliestFullBloom(plant, grow);
}