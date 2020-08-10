package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/8/10.
 */
public class _0108 {
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

        @Override
        public String toString() {
            return "TreeNode{" +
                    "val=" + val +
                    ", left=" + left +
                    ", right=" + right +
                    '}';
        }
    }

    static class Solution {
        private TreeNode root;
        private int[] nums;

        public TreeNode sortedArrayToBST(int[] nums) {
            //二分法
            this.nums = nums;
            int length = nums.length;
            if (length == 0) return null;
            int left = 0;
            int right = length - 1;
            int mid = (right + left) / 2;
            root = new TreeNode(nums[mid]);
            //构建左右子树
            root.left = build(left, mid - 1, root.left);
            root.right = build(mid + 1, length - 1, root.right);
            return root;
        }


        public TreeNode build(int left, int right, TreeNode node) {

            if (left > right) return null;
            int mid = (left + right) / 2;
            if (mid == left) {
                //说明这时候right=left+1
                //或者说right==left
                if (right == left) {
                    node = new TreeNode(nums[mid]);
                    return node;
                } else if (right == left + 1) {
                    node = new TreeNode(nums[mid]);
                    node.right = new TreeNode(nums[mid + 1]);
                    return node;
                }
            } else {
                //如果还比较多，那就继续
                node = new TreeNode(nums[mid]);
                node.left = build(left, mid - 1, node.left);
                node.right = build(mid + 1, right, node.right);
                return node;
            }
            return null;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        solution.sortedArrayToBST(new int[]{0}).toString( );
    }
}
