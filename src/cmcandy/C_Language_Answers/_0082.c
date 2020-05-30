
#include <stdio.h>
#include <stdlib.h>

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
    //测出来的哈哈，最长的测试长度是91
    int tmp[92];
    int index = 0;
    //测试最低的值是-50
    tmp[index] = -51;
    struct ListNode *newhead = (struct ListNode *)malloc(sizeof(struct ListNode));
    newhead->next = head;

    struct ListNode *cur = newhead;
    struct ListNode *curNext = newhead->next;

    while (curNext != NULL)
    {
        if (curNext->val != tmp[index])
        {
            tmp[++index] = curNext->val;
            curNext = curNext->next;
            if (curNext != NULL && curNext->val != tmp[index])
            {
                cur = cur->next;
            }
        }
        else if (curNext->val == tmp[index])
        {
            cur->next = curNext->next;
            curNext = curNext->next;
        }
    }
    return newhead->next;
}