#include <iostream>
#include <string>
#include <vector>

using namespace ::std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //拿到pq的val，然后递归比较，找到最深且值在二者中间的数（可以等于）
        int pd = p->val, qd = q->val;
        return CommonAncestor(root, min(pd, qd), max(pd, qd));
    }
    TreeNode *CommonAncestor(TreeNode *root, int small, int big)
    {
        int dat = root->val;
        if (dat > big)
        {
            //如果在比大数大，则说明在左侧
            return CommonAncestor(root->left, small, big);
        }
        else if (dat < small)
        {
            //如果在比小数小，则说明在右侧
            return CommonAncestor(root->right, small, big);
        }
        return root;
    }
};