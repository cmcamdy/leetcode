#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> hash;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }
    // @brief: 构建二叉树
    // @pram: preorder, inorder: 前序遍历与中序遍历
    //        pl, pr : 当前前序遍历的区间
    //        il, ir : 当前中序遍历的区间
    // @ret: 构建的根节点
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir)
    {
        if (pl > pr)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pl]);
        int k = hash[root->val]; // 根节点在中序遍历的位置
        root->left = build(preorder, inorder, pl + 1, k + pl - il, il, k - 1);
        root->right = build(preorder, inorder, k + pr - ir + 1, pr, k + 1, ir);
        return root;
    }
};