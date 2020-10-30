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
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return root;
        dfs(root,0);
        return root;
    }
    //反中序
    int dfs(TreeNode* root,int sum){
        int left=0,right=0;
        //若左侧非空，遍历左侧，加上
        if(root->right!=NULL) left=dfs(root->right,sum);
        root->val+=left==0?sum:left;
        if(root->left!=NULL) return dfs(root->left,root->val);
        return root->val;
    }
};