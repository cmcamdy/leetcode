
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool isSym(struct TreeNode *left, struct TreeNode *right)
{
    if (!left && !right)
        return true;
    else if ((left && !right) || (!left && right))
        return false;
    else
    {
        if (left->val != right->val)
            return false;
        return isSym(left->left, right->right) && isSym(left->right, right->left);
    }
}

bool isSymmetric(struct TreeNode *root)
{
    if (!root)
        return true;
    return isSym(root->left, root->right);
}