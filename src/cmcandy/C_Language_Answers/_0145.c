
#include <stdio.h>
#include <stdlib.h>
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
void getTreeSize(struct TreeNode *root, int *returnSize)
{
    if (root == NULL)
    {
        (*returnSize) = 0;
        return;
    }
    if (root->left != NULL)
    {
        (*returnSize)++;
        getTreeSize(root->left, returnSize);
    }
    if (root->right != NULL)
    {
        (*returnSize)++;
        getTreeSize(root->right, returnSize);
    }
    return returnSize;
}

int getVal(struct TreeNode *root, int *res, int index)
{
    if (root->left != NULL)
        index = getVal(root->left, res, index);
    if (root->right != NULL)
        index = getVal(root->right, res, index);
    res[index++] = root->val;
    return index;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    (*returnSize) = 1;
    getTreeSize(root, returnSize);
    if ((*returnSize) == 0)
    {
        int *res = (int *)malloc(sizeof(int));
        return res;
    }
    int *res = (int *)malloc(sizeof(int) * (*returnSize));

    getVal(root, res, 0);

    return res;
}