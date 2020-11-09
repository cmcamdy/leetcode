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
    int longestUnivaluePath(TreeNode *root)
    {
        int ans = 0;
        findUnivalPath(root, ans);
        return ans;
    }
    int findUnivalPath(TreeNode *node, int &ans)
    {
        if (node == nullptr)
            return 0;

        int left = findUnivalPath(node->left, ans);
        int right = findUnivalPath(node->right, ans);

        left = (node->left != nullptr && node->val == node->left->val) ? left + 1 : 0;
        right = (node->right != nullptr && node->val == node->right->val) ? right + 1 : 0;

        ans = max(ans, left + right);
        return max(left, right);
    }
};