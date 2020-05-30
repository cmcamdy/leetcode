# include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *p = head;
    while (p->next != NULL)
    {
        if (p->next->val == p->val)
            p->next = p->next->next;
        else
            p = p->next;
    }
    return head;
}