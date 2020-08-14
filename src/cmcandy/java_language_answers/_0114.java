package cmcandy.java_language_answers;

import java.net.Socket;

/**
 * Created by CHEN on 2020/8/14.
 */
public class _0114 {


    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     * int val;
     * TreeNode left;
     * TreeNode right;
     * TreeNode() {}
     * TreeNode(int val) { this.val = val; }
     * TreeNode(int val, TreeNode left, TreeNode right) {
     * this.val = val;
     * this.left = left;
     * this.right = right;
     * }
     * }
     */
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }

        TreeNode(int[] list, int start) {
            if (list[start] != -1) {
                val = list[start];
                TreeNode tmp = this;
                if (start * 2 + 1 < list.length && start * 2 + 1 != -1)
                    tmp.left = new TreeNode(list, start * 2 + 1);
                if (start * 2 + 2 < list.length && start * 2 + 2 != -1)
                    tmp.right = new TreeNode(list, start * 2 + 2);
            }

        }
    }

    static class Solution {
        public void flatten(TreeNode root) {
            while (root != null) {
                //左子树为 null，直接考虑下一个节点
                if (root.left == null) {
                    root = root.right;
                } else {
                    // 找左子树最右边的节点
                    TreeNode pre = root.left;
                    while (pre.right != null) {
                        pre = pre.right;
                    }
                    //将原来的右子树接到左子树的最右边节点
                    pre.right = root.right;
                    // 将左子树插入到右子树的地方
                    root.right = root.left;
                    root.left = null;
                    // 考虑下一个节点
                    root = root.right;
                }
            }
        }
    }

    public static void main(String[] args) {
//        int[] lis = new int[]{1,2,-1,3};
        int[] lis = new int[]{1,-1,2,3};
        TreeNode root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);
        Solution solution = new Solution( );
        solution.flatten(root);
    }
}
