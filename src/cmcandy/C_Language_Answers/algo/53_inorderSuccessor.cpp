
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val > p->val)
        {
            TreeNode *tmp = inorderSuccessor(root->left, p);
            if (tmp == nullptr)
                return root;
            return tmp;
        }
        if (root->val <= p->val)
            return inorderSuccessor(root->right, p);
        return nullptr;
    }
};