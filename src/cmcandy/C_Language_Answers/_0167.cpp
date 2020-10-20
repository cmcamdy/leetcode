#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace ::std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        int len = numbers.size();
        int left = 0,right = len - 1;
        while(left<right){
            if (numbers[left]+numbers[right]>target)
            {
                right--;
            }else if(numbers[left]+numbers[right]<target){
                left++;
            }
            else
            {
                return vector<int>{left+1,right+1};
            }
        }
        return vector<int>{0, 0};
    }
};

int main()
{

    Solution s;
    // int a[] = {2, 7, 11, 15};
    int a[] = {5,25,75};
    vector<int> num(a, a + 3);
    int target = 9;
    s.twoSum(num, target);
}