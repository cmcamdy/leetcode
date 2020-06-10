package cmcandy.java_language_answers;

import java.util.LinkedList;

/**
 * Created by CHEN on 2020/6/7.
 */
public class _0104 {
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     * int val;
     * TreeNode left;
     * TreeNode right;
     * TreeNode(int x) { val = x; }
     * }
     */
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    class Solution {
        public int maxDepth(TreeNode root) {
            int size = 1;
            TreeNode tmp;
            //利用队列来实现层序遍历
            LinkedList<TreeNode> list = new LinkedList<>( );
            int deep = 0;
            if (root == null) return deep;
            list.add(root);
            while (list.size( ) > 0) {
                //开始遍历
                size = list.size( );
                for (int i = 0; i < size; i++) {
                    tmp = list.removeFirst( );
                    //如果还有下一层，那就入队
                    if (tmp.left != null) {
                        list.add(tmp.left);
                    }
                    if (tmp.right != null) {
                        list.add(tmp.right);
                    }
                }
                deep++;
            }
            return deep;
        }
    }
}
