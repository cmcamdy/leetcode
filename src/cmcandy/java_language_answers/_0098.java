package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/7/25.
 */
public class _0098 {
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     * int val;
     * TreeNode left;
     * TreeNode right;
     * TreeNode(int x) { val = x; }
     * }
     */
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    static class Solution {
        public boolean isValidBST(TreeNode root) {
            return judge(root, Long.MAX_VALUE, Long.MIN_VALUE);
        }

        public boolean judge(TreeNode root, long max, long min) {
            boolean jud = true;
            if (root == null) return true;
            if (root.left != null) {
                int tmp = root.left.val;
                if (tmp < root.val && tmp > min) {
                    jud = judge(root.left, root.val, min);
                    if (jud == false) return false;
                } else {
                    return false;
                }
            }
            if (root.right != null) {
                int tmp = root.right.val;
                if (tmp > root.val && tmp < max) {
                    jud = judge(root.right, max, root.val);
                    if (jud == false) return false;
                } else {
                    return false;
                }
            }
            return jud;
        }
    }

    public static void main(String[] args) {
//        [-2147483648,null,2147483647]
        TreeNode treeNode = new TreeNode(-2147483648);
        treeNode.right = new TreeNode(2147483647);
        treeNode.left = new TreeNode(-2147483648);
        Solution solution = new Solution();
        System.out.println(solution.isValidBST(treeNode) );
    }
}
