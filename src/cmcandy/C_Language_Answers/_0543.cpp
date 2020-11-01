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

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
class Solution {
public:
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        getDepth(root);
        return res;
    }
    int getDepth(TreeNode* root){
        int left=0,right=0;
        if(root->left!=NULL) left=getDepth(root->left);
        if(root->right!=NULL) right=getDepth(root->right);
        if(left+right>res)res=left+right;
        // cout<<root->val<<"  "<<left<<"  "<<right<<"  "<<res<<endl;
        return max(left,right)+1;
        
        
    }
};