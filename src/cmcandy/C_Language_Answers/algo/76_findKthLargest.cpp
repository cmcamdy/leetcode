#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace ::std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        quickSort(nums, target, 0, nums.size()-1);
        return nums[target];
    }
    void quickSort(vector<int>& nums, int target, int left, int right){

        int mode = 1;
        int tleft = left, tright = right;

        while(tleft<tright){
            if(nums[tleft]>nums[tright]){
                // swap
                int tmp = nums[tleft];
                nums[tleft] = nums[tright];
                nums[tright] = tmp;

                mode = (mode+1)%2;
            }
            if(mode==1){
                tright--;
            }else tleft++;
        }
        if(tleft == target) return;
        else if(tleft < target) quickSort(nums, target, tleft+1, right);
        else if(tleft > target) quickSort(nums, target, left, tleft-1);
        return;
    }
};
int main(){
    Solution s;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout<<s.findKthLargest(nums,4);

}