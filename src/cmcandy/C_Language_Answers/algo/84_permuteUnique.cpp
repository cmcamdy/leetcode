#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace ::std;


class Solution {
public:
    vector<int> nums;
    int len;
    map<int,int>m;
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->len = nums.size();
        for(auto&num :nums){
            if(m.find(num)== m.end()) {
                m[num] = 1;
                this->nums.push_back(num);
            }
            else m[num]++;
        }
        backtrace(-1);
        return res;
    }
    void backtrace(int idx)
    {
        if (path.size()==len){
            res.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            // 上一次用的数字不准用，避免重复
            if(i!=idx){
                int tmp = m[nums[i]];
                for(int j=0; j<tmp; j++){
                    m[nums[i]]--;
                    path.push_back(nums[i]);
                    backtrace(i);
                }
                for(int j=0; j<tmp; j++){
                    path.pop_back();
                    m[nums[i]]++;
                }
            }
        }
    }
};


int main()
{
    vector<int> nums = {1,1,2};
    int target = 7;
    Solution s;
    s.permuteUnique(nums);
}