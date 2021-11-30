
#include <iostream>
#include <string>
using namespace ::std;

// Definition for singly-linked list.
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *thead = new ListNode(-1, head);
        ListNode *fast = head->next, *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            if (fast == slow)
            {
                fast = thead;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return NULL;
    }
};