package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/8/10.
 */
public class _0110 {
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode(int x) { val = x; }
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
        public boolean isBalanced(TreeNode root) {
            if(root==null) return true;
            int left =  countChild(root.left);
            if(left==-1) return false;
            int right =  countChild(root.right);
            return right==-1||Math.abs(left-right)>1?false:true;
        }


        public int countChild(TreeNode root){
            if(root==null) return 0;
            else{
                int left = countChild(root.left);
                if(left==-1) return -1;
                int right = countChild(root.right);
                return Math.abs(left-right)>1||right==-1?-1:Math.max(left,right)+1;
            }
        }
    }
}
