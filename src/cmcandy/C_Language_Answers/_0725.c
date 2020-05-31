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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode **splitListToParts(struct ListNode *root, int k, int *returnSize)
{

    struct ListNode *cur = root;
    struct ListNode *ptmp;
    struct ListNode **lists = (struct ListNode *)malloc(k * sizeof(struct ListNode *));
    int index = 0;
    while (cur != NULL)
    {
        cur = cur->next;
        index++;
    }

    int len = index / k;
    int remain = index % k;

    cur = root;
    for (int i = 0; i < k; i++)
    {
        lists[i] = cur;
        int size = len + (remain-- > 0 ? 1 : 0);
        if (cur != NULL)
        {
            for (int j = 0; j < size - 1; j++)
            {
                cur = cur->next;
            }
            ptmp = cur;
            cur = cur->next;
            ptmp->next = NULL;
        }
    }
    *returnSize = k;
    return lists;
}