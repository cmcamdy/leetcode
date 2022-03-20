#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace ::std;


class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int mode=0;
        if(nums.size()<3) return 0;
        // if(nums[0]==nums[1]) mode = 0;
        // else {
        //     mode = nums[0]>nums[1]?-1:1;
        // }
        int count = 0;
        // cout<<mode<<endl<<count;
        for(int i=1; i<nums.size(); i++){
            // cout<< nums[i-1]<<" "<<nums[i]<<endl;
            if(mode == -1 && nums[i]>nums[i-1]){
                mode = 1;
                count++;
            }else if(mode == 1 && nums[i]<nums[i-1]){
                mode = -1;
                count++;
            }else if(mode == 0){
                if(nums[i-1]==nums[i]) mode = 0;
                else {
                    mode = nums[i-1]>nums[i]?-1:1;
                }
            }
        }
        return count;
    }   
};
int main(){

    Solution s;
    vector<int> nums = {6,6,5,5,4,1};
    cout<< s.countHillValley(nums);
}