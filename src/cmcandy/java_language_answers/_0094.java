package cmcandy.java_language_answers;

import java.util.*;
/**
 * Created by CHEN on 2020/6/3.
 */
public class _0094 {
    /**
     * Definition for a binary tree node. public class TreeNode { int val; TreeNode
     * left; TreeNode right; TreeNode(int x) { val = x; } }
     */
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    static class Solution {
        private List<Integer> res = new LinkedList<>();
        private Stack<TreeNode> stack = new Stack<>();

        public List<Integer> inorderTraversal(TreeNode root) {
            //  递归解法
            // if (root==null) return res;
            // if(root.left!=null) inorderTraversal(root.left);
            // res.add(root.val);
            // if(root.right!=null) inorderTraversal(root.right);
            // return res;

            //迭代解法
            TreeNode cur = root;
            while (cur != null || !stack.isEmpty()) {
                if (cur != null) {
                    stack.push(cur);
                    cur = cur.left;
                } else {
                    cur = stack.pop();
                    res.add(cur.val);
                    cur = cur.right;
                }
            }
            return res;
        }
    }
}