#include <iostream>
#include <vector>
#include <map>
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
    map<int, int> m;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        return buildTreeImpl(preorder, 0, inorder, 0, inorder.size() - 1);
    }
    TreeNode *buildTreeImpl(vector<int> &preorder, int pl, vector<int> &inorder, int il, int ir)
    {
        if (il > ir)
            return NULL;
        // 首先 pre中找出当前节点
        int index = m[preorder[pl]];
        TreeNode *node = new TreeNode(preorder[pl]);
        // 左节点
        node->left = buildTreeImpl(preorder, pl + 1, inorder, il, index - 1);
        // 右节点
        node->right = buildTreeImpl(preorder, pl + index -il + 1, inorder, index + 1, ir);
        return node;
    }
};

int main(){
    vector<int> preorder = {1,2,3};
    vector<int> inorder = {2,3,1};


    // vector<int> preorder = {3,9,20,15,7};
    // vector<int> inorder = {9,3,15,20,7};
    Solution s;
    TreeNode* head = s.buildTree(preorder, inorder);

}