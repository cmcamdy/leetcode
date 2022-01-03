#include <iostream>
#include <vector>

using namespace ::std;

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
    int maxNum = -1000;
    int maxPathSum(TreeNode *root)
    {
        // 路径可以被分为三种，只经过左侧，只经过右侧，经过两侧
        findPath(root);
        return maxNum;
    }
    int findPath(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
        {
            maxNum = max(maxNum, root->val);
            return root->val;
        }
        int left = 0, right = 0, both = 0;
        // 如果<0这段就不能要
        // 左侧
        if (root->left != nullptr)
            left = max(findPath(root->left), 0);
        maxNum = max(maxNum, left + root->val);
        // 右侧
        if (root->right != nullptr)
            right = max(findPath(root->right), 0);
        maxNum = max(maxNum, right + root->val);
        // 两侧
        both = left + right + root->val;
        maxNum = max(maxNum, both);
        return left > right ? left + root->val : right + root->val;
    }
};