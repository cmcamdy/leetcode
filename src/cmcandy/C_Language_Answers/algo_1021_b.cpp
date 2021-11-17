#include <iostream>
#include <vector>
using namespace ::std;

int main()
{

    long long sum = 0;
    int pre = 0;
    vector<int> nums;
    int tmp;
    while (cin >> tmp)
    {
        nums.push_back(tmp);
    }
    int len = nums.size();
    sum = nums[0];
    for (int i = 0; i < len; i++)
    {
        if (i - pre < 2 && nums[i] > nums[pre])
        {
            sum = sum + nums[i] - nums[pre];
            pre = i;
        }
        else if (i - pre >= 2 && nums[i] > nums[i - 1])
        {
            sum = sum + nums[i] - nums[i - 1];
        }
    }
    cout<<sum;
}