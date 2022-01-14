#include <iostream>
#include <vector>
using namespace ::std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        else if(len == 2) return max(nums[0], nums[1]);
        vector<int> dp(len,0); 
        vector<int> dp2(len,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for(int i=3; i<len; i++){
            dp[i-1] = max(dp[i-3] + nums[i-1], dp[i-2]);
            dp2[i] = max(dp2[i-2] + nums[i], dp2[i-1]);
        }
        return max(dp[len-2], dp2[len-1]);

    }
};

int main(){
    vector<int> nums = {1,7,9,2};
    Solution s;
    cout<<s.rob(nums)<<endl;
}