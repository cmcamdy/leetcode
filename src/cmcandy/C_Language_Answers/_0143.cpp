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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *slow, *fast, *pre;
        if (head == NULL || head->next == NULL)
            return;
        fast = head->next->next;
        pre = head;
        while (fast != NULL && fast->next != NULL)
        {
            pre = pre->next;
            fast = fast->next->next;
        }
        slow = pre->next;
        pre->next = NULL;
        ListNode *tmp1, *tmp2;
        tmp1 = slow;
        slow = slow->next;
        tmp1->next = NULL;
        while (slow != NULL)
        {
            //保存下一个节点的地址
            tmp2 = slow->next;
            slow->next = tmp1;
            tmp1 = slow;
            slow = tmp2;
        }
        slow = head;
        while (slow != NULL)
        {
            tmp2 = tmp1;
            tmp1 = tmp1->next;
            tmp2->next = slow->next;
            slow->next = tmp2;
            if (tmp2->next == NULL && tmp1 != NULL)
            {
                tmp2->next = tmp1;
                break;
            }
            else
            {
                slow = tmp2->next;
            }
        }
    }
};