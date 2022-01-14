#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace ::std;


class Solution {
public:
    vector<int> nums;
    vector<int> used;
    vector<int> path;
    vector<vector<int>> res;
    int len;

    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        this->len = nums.size();
        vector<int> tmp(nums.size(),0);
        this->used = tmp;
        backtrace();
        return res;
    }


    void backtrace()
    {
        if (path.size()==len){
            res.push_back(path);
            return;
        }
        for(int i=0; i<len; i++){
            if(used[i]==0){
                used[i]=1;
                path.push_back(nums[i]);
                backtrace();
                used[i]=0;
                path.pop_back();
            }
        }
    }
};


int main()
{
    vector<int> nums = {1,2,3};
    int target = 7;
    Solution s;
    s.permute(nums);
}