package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/8/18.
 */
public class _0129 {


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
        private int sum = 0;

        public int sumNumbers(TreeNode root) {
            //遍历导叶子节点，加到sum
            if (root == null) {
                return 0;
            }
            if (root.right == null && root.left == null) {
                return root.val;
            }
            if (root.left != null) {
                find_leaf(root.left, root.val * 10);
            }
            if (root.right != null) {
                find_leaf(root.right, root.val * 10);
            }
            return sum;

        }

        public void find_leaf(TreeNode root, int num) {
            num += root.val;
            //找到叶子节点
            if (root.left == null && root.right == null) {
                sum += num;
            }
            if (root.left != null) {
                find_leaf(root.left, num * 10);
            }
            if (root.right != null) {
                find_leaf(root.right, num * 10);
            }
        }
    }

    public static void main(String[] args) {
        TreeNode treeNode = new TreeNode(0);
        treeNode.left = new TreeNode(1);
        Solution solution = new Solution( );
        System.out.println(solution.sumNumbers(treeNode));
    }
}
