
#include <iostream>
#include <vector>
using namespace ::std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        // vector<int>res{nums[0],nums[1]};
        vector<int>res(len,0);
        res[0]=nums[0];
        res[1]=max(nums[0],nums[1]);
        for(int i = 2;i<len;i++){
            res[i]= max(nums[i]+res[i-2],res[i-1]);
        }
        return res[len-1];
    }
};

int main(){
    Solution s;
    // vector<int> nums{1,2,3,1};
    // vector<int> nums{2,7,9,3,1};
    vector<int> nums{2,1,1,2};
    cout<< s.rob(nums);
}