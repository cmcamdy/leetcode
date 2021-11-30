#include <iostream>
#include <string>
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

// Definition for singly-linked list.
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *thead = new ListNode(-1, head);
        ListNode *tmp = head, *tmp2 = thead;

        for (int i = 0; i < n - 1; i++)
        {
            if (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
        }
        while (tmp->next != nullptr)
        {
            tmp2 = tmp2->next;
            tmp = tmp->next;
        }
        tmp2->next = tmp2->next->next;
        return thead->next;
    }
};