#include <iostream>
#include <math.h>

using namespace ::std;

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {

        if (head == NULL)
            return NULL;
        //如果右侧为空则只有一个节点，返回该节点即可
        if (head->next == NULL)
            return new TreeNode(head->val);

        ListNode *slow;
        ListNode *pre = head; //slow前一个节点
        ListNode *fast = head->next->next;

        //当fast还没有走到末尾的时候，继续走，最终找到链表中点
        while (fast != NULL && fast->next != NULL)
        {
            pre = pre->next;
            fast = fast->next->next;
        }
        slow = pre->next;
        TreeNode *root = new TreeNode(slow->val);
        pre->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};