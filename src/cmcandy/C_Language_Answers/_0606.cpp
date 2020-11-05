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
    string tree2str(TreeNode *t)
    {
        if (t == NULL)
            return "";

        return t2s(t);
    }

    string t2s(TreeNode *t)
    {

        if (t->left == NULL && t->right == NULL)
        {
            return to_string(t->val);
        }
        else
        {
            string left = "()", right = "";
            if (t->left != NULL)
                left = "(" + t2s(t->left) + ")";
            if (t->right != NULL)
                right = "(" + t2s(t->right) + ")";
            return to_string(t->val) + left + right;
        }
    }
};