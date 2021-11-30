#include <vector>
#include <iostream>
using namespace ::std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int len = numbers.size();
        int left = 0, right = len - 1;
        vector<int> res(2, 0);
        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
            {
                res[0] = left;
                res[1] = right;
                return res;
            }
            else if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> number = {1,2,4,6,10};
    vector<int> res = s.twoSum(number,8);
    cout<<res[0]<<" "<<res[1];
}