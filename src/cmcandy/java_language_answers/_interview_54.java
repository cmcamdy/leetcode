package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/6/18.
 */
public class _interview_54 {
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
        int tmpk;
        int val = -1;

        public int kthLargest(TreeNode root, int k) {
            tmpk = k;
            findnode(root);
            return val;
        }

        public void findnode(TreeNode node) {
            if (node.right != null) findnode(node.right);
            if (tmpk == 1 && val == -1) {
                val = node.val;
                return;
            }
            if (tmpk > 1) {
                tmpk--;
                if (node.left != null) findnode(node.left);
            }
        }
    }
}
