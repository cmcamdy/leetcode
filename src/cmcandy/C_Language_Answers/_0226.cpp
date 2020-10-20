

#include <iostream>
#include <string>
#include <stack>
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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;
        invert(root);
        return root;
    }
    void invert(TreeNode *root)
    {
        TreeNode *tmp;
        if (root->left != NULL || root->right != NULL)
        {
            tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        if (root->left != NULL)
            invert(root->left);
        if (root->right != NULL)
            invert(root->right);
    }
};