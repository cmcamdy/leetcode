package cmcandy.java_language_answers;

import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/**
 * Created by CHEN on 2020/6/3.
 */
public class _0144 {


    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     * int val;
     * TreeNode left;
     * TreeNode right;
     * TreeNode(int x) { val = x; }
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

    static class Solution {
        private List<Integer> res = new LinkedList<>( );
        private Stack<TreeNode> stack = new Stack<>( );

        public List<Integer> preorderTraversal(TreeNode root) {
            //  递归解法
            // if (root==null) return res;
            // res.add(root.val);
            // if(root.left!=null) preorderTraversal(root.left);
            // if(root.right!=null) preorderTraversal(root.right);
            // return res;

            //迭代解法
            //头先加、转左节点、存右边节点
            TreeNode cur = root;
            while (cur != null || !stack.isEmpty( )) {
                if (cur != null) {
                    res.add(cur.val);
                    stack.push(cur.right);
                    cur = cur.left;
                } else {
                    cur = stack.pop( );
                }
            }
            return res;
        }
    }
}
