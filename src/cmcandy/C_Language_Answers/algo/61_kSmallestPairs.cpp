#include <iostream>
#include <vector>
#include <map>
using namespace ::std;
class Solution
{
public:
    vector<vector<int>> heap;
    map<int, int> m;
    void UpdateHeap()
    {
        int len = heap.size();
        int index = 0, childIndex = 0;

        while (2 * index + 1 < len)
        {
            // // 叶子结点，不需要比较了
            // if(2*index+1 >= len) break;
            // else{
            //这里是还有孩子
            if (heap[2 * index + 1][0] + heap[2 * index + 1][1] > heap[index][0] + heap[index][1])
            {
                // 下降
                childIndex = 2 * index + 1;
            }
            // 存在 && 右孩子比当前childIndex小
            if (2 * index + 2 < len && heap[2 * index + 2][0] + heap[2 * index + 2][1] > heap[index][0] + heap[index][1])
            {
                // 这时候就是和上一个if中小的比了
                childIndex = childIndex == index ? 2 * index + 2 : (heap[2 * index + 2][0] + heap[2 * index + 2][1] < heap[childIndex][0] + heap[childIndex][1] ? childIndex : 2 * index + 2);
            }
            if (childIndex == index)
            {
                break;
            }
            else
            {
                vector<int> tmp = heap[index];
                heap[index] = heap[childIndex];
                heap[childIndex] = tmp;
                index = childIndex;
            }
        }
    }
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        //大根堆，就是用k长的大根堆村最小的几个数对
        int len = nums1.size() * nums2.size();
        vector<vector<int>> tmp(k < len ? k : len, vector<int>(2, 1000000000));
        heap = tmp;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] + nums2[j] < heap[0][0] + heap[0][1])
                {
                    heap[0][0] = nums1[i];
                    heap[0][1] = nums2[j];
                    UpdateHeap();
                }
            }
        }
        return heap;
    }
};
int main()
{
    Solution s;
    // vector<int> nums1 = {1,7,11};
    // vector<int> nums2 = {2,4,6};
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3};
    s.kSmallestPairs(nums1, nums2, 3);
}