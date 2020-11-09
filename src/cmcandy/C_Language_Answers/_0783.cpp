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
    vector<int> nums;
    void translate(TreeNode *root)
    {
        if (root == NULL)
            return;
        translate(root->left);
        nums.push_back(root->val);
        translate(root->right);
    }
    int minDiffInBST(TreeNode *root)
    {
        int res = 100000;
        translate(root);
        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
        {
            res = min(res, nums[i + 1] - nums[i]);
        }
        return res;
    }
};