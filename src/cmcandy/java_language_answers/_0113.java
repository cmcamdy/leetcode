package cmcandy.java_language_answers;

import sun.reflect.generics.tree.Tree;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by CHEN on 2020/8/10.
 */
public class _0113 {
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

        @Override
        public String toString() {
            return "{" + val + "\n"+left + right + '}';
        }
    }

    static class Solution {
        public List<List<Integer>> pathSum(TreeNode root, int sum) {
            if (root == null) return new LinkedList<>( );
            else if (root.left == null && root.right == null) {
                if (root.val - sum == 0) {
                    List<List<Integer>> res = new LinkedList<>( );
                    LinkedList<Integer> tmp = new LinkedList<>( );
                    tmp.add(root.val);
                    res.add(tmp);
                    return res;
                }
            } else {
//                pathSum(root.left, sum - root.val) || pathSum(root.right, sum - root.val)
                List<List<Integer>> res = new LinkedList<>( );
                LinkedList<LinkedList<Integer>> tmp = (LinkedList)pathSum(root.left, sum - root.val);
                tmp.addAll((LinkedList)pathSum(root.right, sum - root.val));
                for (int i = 0; i < tmp.size( ); i++) {
                    tmp.get(i).addFirst(root.val);
                    res.add(new LinkedList<>(tmp.get(i)));
                }
                return res;
            }
            return new LinkedList<>( );
        }
    }

    public static void main(String[] args) {
        int[] lis = new int[]{5, 4, 8, 11, -1, 13, 4, 7, 2, -1,-1,-1, -1, 5, 1};
        TreeNode  root = new TreeNode(lis, 0);
        Solution solution = new Solution();
        solution.pathSum(root,22);
    }
}
