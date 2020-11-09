#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int left=0,right=0;
        int len = nums.size();
        int res=0;
        for(int i =1;i<len;i++){
            if(nums[i]>nums[i-1]){
                //如果满足条件，且left<=right
                right++;
            }
            else if(nums[i]<=nums[i-1]){
                //如果不满足条件，记录长度
                res=res>right-left+1?res:right-left+1;
                left=i;
                right=i;
            }
        }
        return res>right-left+1?res:right-left+1;
    }
};

int main(){

    vector<int> nums{1,3,5,4,7};

    Solution s;
    cout<<s.findLengthOfLCIS(nums)<<endl;


}