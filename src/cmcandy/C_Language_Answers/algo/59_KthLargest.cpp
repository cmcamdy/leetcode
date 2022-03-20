#include <iostream>
#include <vector>
using namespace ::std;

class KthLargest
{
public:
    vector<int> heap;
    void show(){
        for (int i = 0; i < heap.size(); i++)
        {
            cout<< heap[i]<<endl;
        }
    }
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
            if (heap[2 * index + 1] < heap[index])
            {
                // 下降
                childIndex = 2 * index + 1;
            }
            // 存在 && 右孩子比当前childIndex小
            if (2 * index + 2 < len && heap[2 * index + 2] < heap[index])
            {
                // 这时候就是和上一个if中小的比了
                childIndex = childIndex == index ? 2 * index + 2 : (heap[2 * index + 2] > heap[childIndex] ? childIndex : 2 * index + 2);
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
            // }
        }
       
    }
    
    KthLargest(int k, vector<int> &nums)
    {
        //拥有k个节点的小根堆，顶点为最小值，那么每次返回顶点就是第k大了
        vector<int> tmp(k, -10000);
        heap = tmp;
        //小根堆建立
        for (int i = 0; i < nums.size(); i++)
        {
            add(nums[i]);
        }
    }

    int add(int val)
    {
        if (val <= heap[0])
            return heap[0];
        else
        {
            heap[0] = val;
            UpdateHeap();
        }
        // 如果比当前顶点大，那么替换当前顶点，更新一下树
        return heap[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main(){
    // vector<int> nums = {4,5,8,2};
    vector<int> nums;
    KthLargest k =  KthLargest(1,nums);
    cout<<k.add(-3);
}