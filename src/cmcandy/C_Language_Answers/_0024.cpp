#include <iostream>

using namespace ::std;
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
    ListNode *swapPairs(ListNode *head)
    {
        //基本情况
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre = NULL, *now = head, *alf = head->next, *ntu = alf->next;

        while (ntu != NULL && ntu->next != NULL)
        {
            if (pre == NULL)
                head = alf;
            else
                pre->next = alf;
            //1->3
            now->next = ntu;
            //2->1
            alf->next = now;

            if (ntu == NULL || ntu->next == NULL)
                break;
            //next turn
            pre = now;
            now = now->next;
            alf = now->next;
            ntu = alf->next;
        }
        //最后一轮儿
        if (pre == NULL)
            head = alf;
        else
            pre->next = alf;
        now->next = ntu;
        alf->next = now;
        return head;
    }
};