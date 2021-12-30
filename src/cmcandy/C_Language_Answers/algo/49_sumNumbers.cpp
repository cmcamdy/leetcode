
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
    int sumNumbers(TreeNode *root)
    {
        return sumNumbersImpl(root, 0);
    }
    int sumNumbersImpl(TreeNode *root, int parentNum)
    {
        // cout<<parentNum<<endl;
        if (root == nullptr)
            return 0;
        int num = root->val;
        int left = 0, right = 0;
        if (root->left != nullptr)
        {
            left = sumNumbersImpl(root->left, parentNum * 10 + num);
        }
        if (root->right != nullptr)
        {
            right = sumNumbersImpl(root->right, parentNum * 10 + num);
        }
        return root->left == nullptr && root->right == nullptr ? parentNum * 10 + num : left + right;
    }
};