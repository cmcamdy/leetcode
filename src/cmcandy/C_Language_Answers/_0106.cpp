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
class Solution {
public:
    unordered_map<int, int> hash;
    // map<int, int> hash;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;
        return build(postorder, inorder, 0, postorder.size() - 1, 0, postorder.size() - 1);
        
    }
    //        pl, pr : 当前后续遍历的区间
    //        il, ir : 当前中序遍历的区间
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int pl, int pr, int il, int ir)
    {
        if (pl > pr) return nullptr;
        TreeNode* root = new TreeNode(postorder[pr]);
        // 根节点在中序遍历的位置
        int k = hash[root->val]; 
        // 这里分清楚界限就行，
        root->left  = build(postorder, inorder,pl ,k + pl - il - 1 ,il, k - 1);
        root->right = build(postorder, inorder, k + pr - ir,pr-1,k + 1 , ir);
        return root;
    }
};

