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

struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *small = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *big = (struct ListNode *)malloc(sizeof(struct ListNode));

    //定义仨指针
    struct ListNode *pSmall = small;
    struct ListNode *pBig = big;

    while (head)
    {
        if (head->val < x)
        {
            pSmall->next = head;
            pSmall = pSmall->next;
        }
        else
        {
            pBig->next = head;
            pBig = pBig->next;
        }
        head = head->next;
    }

    pBig->next = NULL;
    pSmall->next = big->next;

    return small->next;
}