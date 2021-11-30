#include <iostream>
#include <string>
#include <stack>
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<ListNode *> s;
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        while (slow != nullptr)
        {
            s.push(slow);
            slow = slow->next;
        }
        ListNode *tmp = head;
        while (tmp != nullptr && !s.empty())
        {
            if (s.top()->val != tmp->val)
            {
                return false;
            }
            s.pop();
            tmp = tmp->next;
        }
        return true;
    }
};