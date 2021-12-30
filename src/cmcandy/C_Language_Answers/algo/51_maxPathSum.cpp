#include <iostream>
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
        maxPathSumImpl(root);
        return maxNum;
    }
    int maxPathSumImpl(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        // max(单边+val，只有val，双边+val )==>localMax，然后维护一个全局max即可
        int left = maxPathSumImpl(root->left);
        int right = maxPathSumImpl(root->right);
        int localMax = max(max(max(left, right) + root->val, left + right + root->val), root->val);
        maxNum = max(maxNum, localMax);
        return max(max(left, right), 0) + root->val;
    }
};