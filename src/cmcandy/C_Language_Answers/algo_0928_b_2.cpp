#include <cstdio>
#include <vector>
#include <algorithm>    // std::find
using namespace ::std;
const int N = 1e5 + 10;

void searchRange(int* nums,int len, int target) {
    vector<int> ans = {-1, -1};
    //查找第一个大于或等于target的元素的迭代器
    auto it_begin = lower_bound(nums, nums+len, target);
    //如果找到且等于target
    if(it_begin != nums+len && *it_begin == target)
        ans[0] = it_begin - nums;
    //查找第一个大于target的元素的迭代器
    auto it_end = upper_bound(nums, nums+len, target);
    //当nums只有一个元素时且大于或等于target时，it_end肯定会指向nums.end()
    //                    小于时，nums.begin() == it_end，此时返回-1
    if(it_end != nums && *(it_end - 1) == target)
        ans[1] = it_end - nums - 1;
    printf("%d %d\n", ans[0], ans[1]);
    
}
int main()
{
    int nlen, tlen, nums[N], index, target, last = -1;
    scanf("%d %d", &nlen, &tlen);
    bool test1, test2;
    for (int i = 0; i < nlen; ++i)
        scanf("%d", &nums[i]);
    for (int i = 0; i < tlen; i++)
    {
        scanf("%d", &target);
        searchRange(nums,nlen,target);
    }
    return 0;
}