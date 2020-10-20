/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *tmpA = headA;
        ListNode *tmpB = headB;
        int lenA = 0;
        int lenB = 0;
        while (tmpA != NULL)
        {
            tmpA = tmpA->next;
            lenA++;
        }
        while (tmpB != NULL)
        {
            tmpB = tmpB->next;
            lenB++;
        }
        tmpA = headA;
        tmpB = headB;
        if (lenA > lenB)
        {
            for (int i = 0; i < lenA - lenB; i++)
                tmpA = tmpA->next;
        }
        else if (lenA < lenB)
        {
            for (int i = 0; i < lenB - lenA; i++)
                tmpB = tmpB->next;
        }
        ListNode *value = NULL;
        while (tmpA != NULL)
        {
            if (value == NULL && tmpB == tmpA)
                value = tmpA;
            else if (tmpA != tmpB)
                value = NULL;
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return value;
    }
};

int main()
{

    Solution s;
    ListNode *head1 = s.createList({1});
    ListNode *head2 = s.createList({1});

    s.getIntersectionNode(head1, head2);
}