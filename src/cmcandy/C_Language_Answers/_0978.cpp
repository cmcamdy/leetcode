#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        //now表示当前最长
        int res = 1, now = 1, type = 1;
        int len = arr.size();

        for (int i = 0; i < len - 1; i++)
        {   
            //当相等的时候应当断掉，并跳过这个元素
            if(arr[i]==arr[i+1]){
                res = max(res, now);
                now = 1;
            }
            //模式1=情况1
            else if (type == 1)
            {
                if ((i % 2 == 0 && arr[i] < arr[i + 1]) || (i % 2 == 1 && arr[i] > arr[i + 1]))
                {
                    now++;
                }
                else if ((i % 2 == 0 && arr[i] > arr[i + 1]) || (i % 2 == 1 && arr[i] < arr[i + 1]))
                {
                    res = max(res, now);
                    now = 2;
                    type = 0;
                }
            }
            //模式2=情况2
            else if (type == 0)
            {
                if ((i % 2 == 0 && arr[i] < arr[i + 1]) || (i % 2 == 1 && arr[i] > arr[i + 1]))
                {
                    res = max(res, now);
                    now = 2;
                    type = 1;
                }
                else if ((i % 2 == 0 && arr[i] > arr[i + 1]) || (i % 2 == 1 && arr[i] < arr[i + 1]))
                {
                    now++;
                }
            }
        }
        return res > now ? res : now;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    // vector<int> nums{9,4,2,10,7,8,8,1,9};
    // vector<int> nums{4,8,12,16};
    vector<int> nums{8,8,9,10,6,8,2,4,2,2,10,6,6,10,10,2,3,5,1,2,10,4,2,0,9,4,9,3,0,6,3,2,3,10,10,6,4,6,4,4,2,5,1,4,1,1,9,8,9,5,3,5,5,4,5,5,6,5,3,3,7,2,0,10,9,7,7,3,5,1,0,9,6,3,1,3,4,4,3,6,3,2,1,4,10,2,3,4,4,3,6,7,6,2,1,7,0,6,8,10};
    Solution s;
    int res = s.maxTurbulenceSize(nums);
    cout<<res;
    return 0;
}
