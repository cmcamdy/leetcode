#include <iostream>
#include <vector>

using namespace ::std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        vector<ListNode &> li;
        ListNode *tmp = head;
        while (tmp != NULL)
        {
            //这里出了问题，好像不能这么初始化
            li.push_back(*tmp);
            tmp = tmp->next;
        }
        
        
        tmp = head;
        int len = li.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (i == len - 1 - i)
            {
                *tmp->next = li[i];
                break;
            }
            if (i != 0)
            {
                *tmp->next = li[i];
                tmp = tmp->next;
            }
            *tmp->next = li[len - 1];
            tmp = tmp->next;
        }
    }
    ListNode *createList(vector<int> nums)
    {
        int len = nums.size();
        ListNode *head;
        ListNode *tmp;
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                tmp = new ListNode(nums[i]);
                head = tmp;
            }
            else
            {
                tmp->next = new ListNode(nums[i]);
                tmp = tmp->next;
            }
            // cout<<tmp->val<<endl;
        }
        return head;
    }
};
int main()
{
    Solution s;
    // [1,2,3,4]
    ListNode *head = s.createList({1, 2, 3, 4});
    s.reorderList(head);
}