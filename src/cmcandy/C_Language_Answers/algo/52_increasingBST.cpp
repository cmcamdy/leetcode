#include <iostream>
#include <stack>
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
    stack<TreeNode *> s;
    TreeNode *increasingBST(TreeNode *root)
    {
        dfs(root);
        TreeNode *tmp = nullptr;
        while (!s.empty())
        {
            s.top()->right = tmp;
            s.top()->left = nullptr;
            tmp = s.top();
            s.pop();
        }
        return tmp;
    }
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        s.push(root);
        dfs(root->right);
    }
};