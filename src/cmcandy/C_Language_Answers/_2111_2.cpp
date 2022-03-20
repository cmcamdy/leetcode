#include <iostream>
#include <vector>
#include <string>
using namespace ::std;

// 对于给定的一个序列，如果我们希望通过修改最少的元素，使得它单调递增，那么最少需要修改的元素个数，就是「序列的长度」减去「序列的最长递增子序列」的长度。
// 超时了
class Solution
{
public:
    int kIncreasing(vector<int> &arr, int k)
    {
        //当前递增数now、最大递增数res
        int len = arr.size();
        if (len <= 1)
            return 0;
        // 主要是为了得到最长字串
        // 表示以此为结尾的最大的增长序列长度
        vector<int> dp(arr.size(), 1);
        vector<int> res(k, 0);
        int max_num = 1, quo = arr.size() / k, remain = arr.size() % k;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i - k; j >= 0; j -= k)
            {
                if (arr[j] <= arr[i])
                {
                    max_num = max(dp[j] + 1, max_num);
                }
            }
            dp[i] = max_num;
            res[i % k] = max(res[i % k], max_num);
            max_num = 1;
        }
        int minChange = 0;
        for (int i = 0; i < k; i++)
        {
            minChange += quo - res[i] + (i < remain ? 1 : 0);
        }
        return minChange;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {5, 4, 3, 2, 1};
    int k = 1;
    cout << s.kIncreasing(arr, k) << endl;
    arr = {4, 1, 5, 2, 6, 2};
    k = 2;
    cout << s.kIncreasing(arr, k) << endl;
    k = 3;
    cout << s.kIncreasing(arr, k) << endl;
}

