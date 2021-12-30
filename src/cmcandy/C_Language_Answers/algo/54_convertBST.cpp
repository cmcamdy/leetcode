struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
class Solution
{
public:
    TreeNode *convertBST(TreeNode *root)
    {

        dfs(root, 0);
        return root;
    }
    int dfs(TreeNode *root, int larger)
    {
        // 这里考虑到叶子结点的孩子的情况，如果本身整颗树就是null，那么会传入0，因此可以合起来
        if (root == nullptr)
            return larger;

        int right = dfs(root->right, larger);
        root->val += right;
        int left = dfs(root->left, root->val);
        return left;
    }
};