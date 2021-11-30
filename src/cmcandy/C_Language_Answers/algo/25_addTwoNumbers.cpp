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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<ListNode *> s1, s2;
        ListNode *tmp = nullptr, *tmp1, *tmp2;
        int carry = 0;
        while (l1 != nullptr)
        {
            s1.push(l1);
            l1 = l1->next;
            // cout<<s1.top()->val<<" "<<l1->val;
        }
        while (l2 != nullptr)
        {
            s2.push(l2);
            l2 = l2->next;
        }
        while (!s1.empty() && !s2.empty())
        {
            tmp1 = s1.top();
            tmp2 = s2.top();
            tmp1->val += tmp2->val + carry;
            carry = 0;
            if (tmp1->val >= 10)
            {
                tmp1->val -= 10;
                carry = 1;
            }
            tmp1->next = tmp;
            tmp = tmp1;
            s1.pop();
            s2.pop();
        }
        if (!s2.empty())
            s1 = s2;

        while (!s1.empty())
        {
            tmp1 = s1.top();
            tmp1->val += carry;
            carry = 0;
            if (tmp1->val >= 10)
            {
                tmp1->val -= 10;
                carry = 1;
            }
            tmp1->next = tmp;
            tmp = tmp1;
            s1.pop();
        }
        if (carry != 0)
        {
            tmp1 = new ListNode(carry, tmp);
            return tmp1;
        }
        return tmp;
    }
};