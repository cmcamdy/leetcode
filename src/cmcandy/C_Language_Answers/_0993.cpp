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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        return calDepth(root, x, y, 0) == 0 ? true : false;
    }
    //找到各节点的深度并返回
    //没找到返回-1
    //找到了，但在同一父节点下，返回-1（两个返回depth都为1）
    //找到了，且值是相同且>1则是符合条件的
    int calDepth(TreeNode *root, int x, int y, int depth)
    {
        //如果没找到，直接返回-1
        if (root == NULL)
            return -1;
        //如果找到，直接返回1
        if (root->val == x || root->val == y)
            return 1;
        //这里默认元素只出现一次
        int left = calDepth(root->left, x, y, depth + 1);
        int right = calDepth(root->right, x, y, depth + 1);
        if (left == 0 || right == 0 || (left == right && left > 1))
            return 0;
        else if (left != right && (left == -1 || right == -1))
            return max(left, right) + 1;
        else if (left == right && left == 1)
            return -1;
        return -1;
    }
};