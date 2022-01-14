#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace ::std;

class Solution {
public:
    vector<int> nums;
    int n;
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        backtrace(0);
        return res;
    }
    void backtrace(int idx){
        // 到底了，回退
        if(idx == n){
            res.push_back(path);
            return;
        }
        
        // 没有nums[idx]的子集
        backtrace(idx+1);

        // 有nums[idx]的子集
        path.push_back(nums[idx]);
        backtrace(idx+1);
        path.pop_back();
    }
};