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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int jud,cnt=0;
    int pathSum(TreeNode* root, int sum) {
        jud=sum;
        path1(root);
        return cnt;
    }
    void path1(TreeNode* root){
        if(root==NULL)return;
        //每次找该点到所有点的距离
        path2(root,0);
        path1(root->left);
        path1(root->right);
        return;
    }
    void path2(TreeNode* root,int len){
        if(root==NULL) return;
        int tmp=root->val+len;
        if(tmp==jud) cnt++;
        path2(root->left,tmp);
        path2(root->right,tmp);
        
    }
};