#include<map>
#include<iostream>
using namespace::std;

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
    map<long long, int> m;

    int pathSum(TreeNode* root, int targetSum) {
        m[0] = 1;
        return pathSumImpl(root,targetSum,0);
    }
    int pathSumImpl(TreeNode* root,int targetSum,long long curr){
        // 前缀和 = 根节点到该节点的和，该题维护一条路径的前缀和，然后寻找适合的即可，然后利用hashmap减少查找次数
        if(root==nullptr) return 0;
        int res = 0;
        curr += root->val;
        if(m.find(curr - targetSum) != m.end()){
            res = m[curr - targetSum];
        }
        if(m.find(curr) != m.end()){
            m[curr]++;
        }else
            m[curr] = 1;
        res += pathSumImpl(root->left,targetSum,curr);
        res += pathSumImpl(root->right,targetSum,curr);
        m[curr]--;
        return res;
    }
};
