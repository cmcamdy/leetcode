#include <iostream>
#include <vector>
#include <map>
using namespace ::std;

class Solution
{
public:
    vector<int> heap;
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
            if (m[heap[2 * index + 1]] < m[heap[index]])
            {
                // 下降
                childIndex = 2 * index + 1;
            }
            // 存在 && 右孩子比当前childIndex小
            if (2 * index + 2 < len && m[heap[2 * index + 2]] < m[heap[index]])
            {
                // 这时候就是和上一个if中小的比了
                childIndex = childIndex == index ? 2 * index + 2 : (m[heap[2 * index + 2]] > m[heap[childIndex]] ? childIndex : 2 * index + 2);
            }
            if (childIndex == index)
            {
                break;
            }
            else
            {
                int tmp = heap[index];
                heap[index] = heap[childIndex];
                heap[childIndex] = tmp;
                index = childIndex;
            }
        }
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 首先你得有数和数量，这可以用一个map存
        m[-1000000] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
            {
                m[nums[i]]++;
            }
            else
            {
                m[nums[i]] = 1;
            }
        }
        // 然后把这些排排序，取前K个
        map<int, int>::iterator iter;
        vector<int> tmp(k, -1000000);
        heap = tmp;
        // m.begin;
        iter = m.begin();
        // iter = m.begin;
        while (iter != m.end())
        {
            if (iter->second > m[heap[0]])
            {
                heap[0] = iter->first;
                UpdateHeap();
            }
            iter++;
        }
        return heap;
    }
};
int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution s;
    s.topKFrequent(nums,2);

}