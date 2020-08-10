package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/8/10.
 */
public class _0112 {
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
        public boolean hasPathSum(TreeNode root, int sum) {
            if (root == null) return false;
            else if (root.left == null && root.right == null) {
                return root.val - sum == 0;
            } else {
                return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
            }
        }
    }
}
