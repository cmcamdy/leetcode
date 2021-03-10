#include <iostream>
#include <limits.h>
#include <vector>
using namespace ::std;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int len = arr.size();
        int res = 0,now=0;
        //跑k轮
        for(int i = 0; i<k; i++){
            for(int j = 0; j<len; j++){
                now = (arr[j]+now)>0?(arr[j]+now)%(1000000007):0;
                res = max(now,res);
                // cout<<res<<endl;
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr{10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};

    s.kConcatenationMaxSum(arr,100000);
    return 0;
}
