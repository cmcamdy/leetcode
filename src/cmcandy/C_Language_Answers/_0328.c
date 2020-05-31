
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
struct ListNode *oddEvenList(struct ListNode *head)
{
    //奇偶两条数组，最后合起来
    struct ListNode *cur = head;
    struct ListNode *oddNum, *oddHead;
    struct ListNode *evenNum, *evenHead;

    oddHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    evenHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    oddNum = oddHead;
    evenNum = evenHead;
    int tag = 0;
    while (cur != NULL)
    {
        //if old
        if (tag == 0)
        {
            oddNum->next = cur;
            oddNum = oddNum->next;
            tag = 1;
        }
        else if (tag == 1)
        {
            //if even
            evenNum->next = cur;
            evenNum = evenNum->next;
            tag = 0;
        }
        cur = cur->next;
    }
    evenNum->next = NULL;
    //mix
    oddNum->next = evenHead->next;
    return oddHead->next;
}