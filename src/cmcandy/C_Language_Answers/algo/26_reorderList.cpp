
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
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;
        // tmp1 用于奇数链形成，index用于指向，s用于偶数链存储
        ListNode *fast = head, *slow = head;
        stack<ListNode *> s;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow != nullptr)
        {
            s.push(slow);
            slow = slow->next;
        }
        ListNode *tmp = head;
        while (tmp != nullptr && !s.empty())
        {
            s.top()->next = tmp->next;
            tmp->next = s.top();
            tmp = tmp->next->next;
            s.pop();
        }
        tmp->next = nullptr;
        return;
    }
};