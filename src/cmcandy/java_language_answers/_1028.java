package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/6/18.
 */
public class _1028 {
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
        String str;
        int strIndex = 0;
        int depth = 0;
        TreeNode root;

        public TreeNode recoverFromPreorder(String S) {

            str = S;
            int val=0;
            while (strIndex<str.length()&&str.charAt(strIndex) != '-') {
                val = val*10+str.charAt(strIndex)-'0';
                strIndex++;
            }
            root = new TreeNode(val);

            root.left = new TreeNode(-1);
            if (!buildTree(1, root.left)) root.left = null;
            root.right = new TreeNode(-1);
            if (!buildTree(1, root.right))root.right=null;
            return root;
        }

        public boolean buildTree(int dep, TreeNode node) {


            while (strIndex<str.length()&&str.charAt(strIndex) == '-') {
                depth++;
                strIndex++;
            }
            if (depth == dep) {
                int val = 0;
                while (strIndex<str.length()&&str.charAt(strIndex) != '-') {
                    val = val*10+str.charAt(strIndex)-'0';
                    strIndex++;
                }
                node.val = val;
                depth = 0;
                node.left = new TreeNode(-1);
                if (!buildTree(dep + 1, node.left)) node.left=null;
                node.right = new TreeNode(-1);
                if (!buildTree(dep + 1, node.right))node.right=null;
            }else{return false;}
            return true;
        }

    }

    public static void main(String[] args) {
        String S = "1-2--3--4-5--6--7";
        Solution solution = new Solution();
        solution.recoverFromPreorder(S);
    }
}
