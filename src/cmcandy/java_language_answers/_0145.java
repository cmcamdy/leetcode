package cmcandy.java_language_answers;

import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/**
 * Created by CHEN on 2020/6/3.
 */
public class _0145 {

    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode(int x) { val = x; }
     * }
     */
    static public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
    class Solution {
        private LinkedList<Integer> res = new LinkedList<>( );
        private Stack<TreeNode> stack = new Stack<>( );
        public List<Integer> postorderTraversal(TreeNode root) {
            // //  递归解法
            if (root==null) return res;
            // if(root.left!=null) postorderTraversal(root.left);
            // if(root.right!=null) postorderTraversal(root.right);
            // res.add(root.val);
            // return res;

            //迭代解法
            //正常遍历，就是反着插入就行
            stack.push(root);
            TreeNode cur ;
            while (!stack.isEmpty( )) {
                cur = stack.pop();
                res.addFirst(cur.val);
                if (cur.left != null) {
                    stack.push(cur.left);
                }
                if(cur.right!=null){
                    stack.push(cur.right);
                }
            }
            return res;
        }
    }
}
