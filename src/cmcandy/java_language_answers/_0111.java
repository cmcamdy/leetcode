package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/8/10.
 */
public class _0111 {
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

    static class Solution {
        public int minDepth(TreeNode root) {
            if (root == null) return 0;
            else if (root.left == null && root.right == null) return 1;
            else {
                if (root.left == null) return minDepth(root.right) + 1;
                if (root.right == null) return minDepth(root.left) + 1;
                return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
            }
        }
    }
}
