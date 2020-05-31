package cmcandy.Java_Language_Answers;

public class _0101 {
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
        public boolean isSymmetric(TreeNode root) {
            if (root == null)
                return true;
            return isSym(root.left, root.right);
        }

        public boolean isSym(TreeNode left, TreeNode right) {
            if (left == null && right != null || left != null && right == null)
                return false;
            else if (left == null && right == null)
                return true;
            else {
                if (left.val != right.val)
                    return false;
                return isSym(left.left, right.right) && isSym(left.right, right.left);
            }

        }

    }

}