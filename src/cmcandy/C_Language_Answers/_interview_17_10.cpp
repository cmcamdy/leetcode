#include <iostream>
#include <vector>
#include <map>
using namespace ::std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> hash;
        map<int, int>::iterator iter;
        int len = nums.size();
        int half = len / 2;
        for (int i = 0; i < len; i++)
        {
            if (hash.find(nums[i]) != hash.end())
                hash[nums[i]]++;
            else
                hash[nums[i]] = 1;
        }
        iter = hash.begin();
        while (iter != hash.end())
        {
            if (iter->second > half)
                return iter->first;
            iter++;
        }
        return -1;
    }
};