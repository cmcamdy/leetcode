#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() < k)
            k %= nums.size();
        turn_over(nums, 0, nums.size() - 1);
        turn_over(nums, k, nums.size() - 1);
        turn_over(nums, 0, k - 1);
    }
    void turn_over(vector<int> &nums, int begin, int end)
    {
        while (begin < end)
        {
            int tmp = nums[begin];
            nums[begin++] = nums[end];
            nums[end--] = tmp;
        }
    }
};
int main(){
    int a=0;
    cout<<"al";
    cout<<"al";
    cout<<"al";
}