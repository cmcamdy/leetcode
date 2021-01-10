#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        int len = nums.size();
        if (len == 0)
            return res;
        if (len == 1)
        {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int start = nums[0];
        //由于是有序数组，因此只需要判断有没有断开即可
        for (int i = 1; i < len; i++)
        {
            if (nums[i] != nums[i-1] + 1)
            {
                //断了，push一段
                if (start == nums[i-1])
                    res.push_back(to_string(start));
                else
                {
                    res.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                }
                //下一轮
                start = nums[i];
                
            }
        }
        //最后一段
        if (start == nums[len-1])
            res.push_back(to_string(start));
        else
        {
            res.push_back(to_string(start) + "->" + to_string(nums[len-1]));
        }
        return res;
    }
};

int main()
{
    /* code */
    vector<int> nums = {0,1,2,4,5,7};
    Solution s;
    vector<string> res = s.summaryRanges(nums);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}