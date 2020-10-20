#include <iostream>
#include <string>
#include <stack>

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int t = 0;
        ListNode *left = head;
        ListNode *right = head;
        while (right->next != NULL && t++ < n)
            right = right->next;
        if (t < n)
            return left->next;
        while (right->next != NULL)
        {
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        return head;
    }
};