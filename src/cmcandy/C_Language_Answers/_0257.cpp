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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return res;
        paths(root,"");
        return res;
    }
    void paths(TreeNode* root,string path){
        string dat="";
        if(path!="")
             dat= path+"->"+to_string(root->val);
        else
             dat= to_string(root->val);
        if (root->left!=NULL)
        {
            paths(root->left,dat);
        }
        if (root->right!=NULL)
        {
            paths(root->right,dat);
        }
        if(root->right==NULL&&root->left==NULL){
            res.push_back(dat);
        }
    }
};