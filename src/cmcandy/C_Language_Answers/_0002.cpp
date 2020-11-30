#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace ::std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
        ListNode *head = l1;
        int add = 0;
        while (l1 != NULL && l2 != NULL)
        {
            l1->val += l2->val + add;
            if (add == 1)
                l1->val++;
            if (l1->val >= 10)
            {
                l1->val -= 10;
                add = 1;
            }
            else
            {
                add = 0;
            }
            if (l1->next == NULL)
            {
                l1->next = l2->next;
                //接上l2还是null的话就到底了，此时的进位必须新建节点了
                if (l1->next == NULL && add == 1)
                {
                    l1->next = new ListNode(1);
                    add = 0;
                }
                l1 = l1->next;
                break;
            }
            else
            {
                l2 = l2->next;
                l1 = l1->next;
            }
        }

        //解决不等长问题
        while (l1 != NULL && add == 1)
        {
            l1->val++;
            if (l1->val >= 10)
            {
                l1->val -= 10;
                add = 1;
            }
            else
            {
                add = 0;
            }
            if (l1->next == NULL && add == 1)
            {
                l1->next = new ListNode(1);
                break;
            }
            else
            {
                l1 = l1->next;
            }
        }
        return head;
    }
};