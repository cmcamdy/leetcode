#include <iostream>
#include <string.h>
#include <vector>

using namespace ::std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 需要考虑正负号的问题
        // dp表示0-i中非0连续子数组的的乘积
        // 维护一个候选dp，该数组要求子数组乘积和的绝对值最大
        // 维护一个maxNum
        int len = nums.size();
        vector<int>dp(len, -10000); 
        dp[0] = nums[0];
        int maxNum = dp[0];
        int firstneg=nums[0]<0?0:-1,tag=nums[0]==0?1:-1;
        for(int i=1; i<len; i++){
            
            if(nums[i]<0 && firstneg==-1){
                firstneg = i;
            }
            if(tag == 1){
                dp[i] = nums[i];
                tag = -1;
            }
            else
                dp[i] = dp[i-1]*nums[i];
            maxNum = max(dp[i],maxNum);
            if(nums[i] == 0){
                if(dp[i-1]<0 && (i-1)>firstneg){
                    //需要删掉一个负号
                    maxNum = max(maxNum, dp[i-1]/dp[firstneg]);
                }
                firstneg = -1;
                tag = 1;
            }
        }   
        if(dp[len-1]<0 && (len-1)>firstneg){
            //需要删掉一个负号
            maxNum = max(maxNum, dp[len-1]/dp[firstneg]);
        }
        return maxNum;
    }
};
int main(){

    Solution s;
    vector<int> nums = {3,-1,4};
    cout<<s.maxProduct(nums);
}