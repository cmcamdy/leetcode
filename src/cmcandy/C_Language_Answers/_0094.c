
#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void getTreeSize(struct TreeNode* root ,int* returnSize){
    if(root==NULL){
        (*returnSize) = 0;
        return;
    }
    if(root->left!=NULL) {
        (*returnSize)++;
        getTreeSize(root->left,returnSize);
    }
    if(root->right!=NULL) {
        (*returnSize)++;
        getTreeSize(root->right,returnSize);
    }
    return ;
}

int getVal(struct TreeNode* root,int* res,int index){

    if(root->left!=NULL) index = getVal(root->left,res,index);
    res[index++] = root->val;
    if(root->right!=NULL) index = getVal(root->right,res,index);
    return index;

}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    (*returnSize) = 1;
    getTreeSize(root,returnSize);
    int* res = (int*) malloc(sizeof(int)*(*returnSize));
    if((*returnSize) ==0) return res;
    
    getVal(root,res,0);
    return res;
}