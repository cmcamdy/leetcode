
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL)
            return false;
        if (s->val == t->val && isSameTree(s, t))
            return true;
        if (s->left != NULL && isSubtree(s->left, t))
            return true;
        if (s->right != NULL && isSubtree(s->right, t))
            return true;
        return false;
    }

    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        if ((s == NULL && t != NULL) || (s != NULL && t == NULL))
            return false;
        else if (s == NULL && t == NULL)
            return true;
        if (s->val == t->val)
        {
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        }
        else if (s->val != t->val)
            return false;
        return false;
    }
};