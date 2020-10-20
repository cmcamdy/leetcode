
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace ::std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *tmp = head;
        while (tmp != NULL)
        {
            if (tmp == head && tmp->val == val)
            {

                head = head->next;
                tmp = head;
            }
            else
            {
                if (tmp->next!=NULL&&tmp->next->val == val)
                {
                    tmp->next = tmp->next->next;
                }
                else
                {
                    tmp = tmp->next;
                }
            }
        }
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head1 = s.createList({1, 2, 6, 3, 4, 5, 6});
    s.removeElements(head1, 6);
}
