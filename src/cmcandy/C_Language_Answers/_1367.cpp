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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;
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
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        return isSubPathHelp(head, root, true);
    }
    bool isSubPathHelp(ListNode *head, TreeNode *root, bool isRoot)
    {
        //递归出口，head为空则代表走完了
        if (head == nullptr)
            return true;
        else if (root == nullptr)
            return false;
        //当前值匹配，往下找
        if (head->val == root->val)
        {
            if (isSubPathHelp(head->next, root->left, false) || isSubPathHelp(head->next, root->right, false))
                return true;
        }
        //当前值不匹配，但是呢，head是头，可以root向下再匹配
        if (isRoot == true)
            return isSubPathHelp(head, root->left, true) || isSubPathHelp(head, root->right, true);
        return false;
    }
};