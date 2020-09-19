#include <iostream>
#include <map>
#include <vector>

using namespace::std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur=0;
        map<int,int>m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i])==m.end())
            {
                //如果找不到,则加入
                m[nums[i]]=1;
                nums[cur++] = nums[i];
            }
        }
        return cur;
    }
};