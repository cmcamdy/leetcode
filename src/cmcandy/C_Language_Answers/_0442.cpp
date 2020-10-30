#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<len;i++){
            while(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        vector<int> res;
        for(int i =0;i<len;i++){
            if(nums[i]!=i+1){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};