
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
    TreeNode *pruneTree(TreeNode *root)
    {
        return postTra(root) ? nullptr : root;
    }

    bool postTra(TreeNode *root)
    {
        //是否为0
        if (root == nullptr)
            return true;
        bool left = postTra(root->left), right = postTra(root->right);
        if (left)
            root->left = nullptr;
        if (right)
            root->right = nullptr;
        return left && right && (root->val == 0);
    }
};