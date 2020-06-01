
import java.util.*;
public class _0637 {
    /**
     * Definition for a binary tree node. public class TreeNode { int val; TreeNode
     * left; TreeNode right; TreeNode(int x) { val = x; } }
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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new LinkedList<>();
        if(root==null) return res;

        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int ave = 0;
        int size = 1;
        TreeNode tmp;
        
        while(size!=0){
        
            for(int i =0;i<size;i++){
                tmp = queue.removeLast();
                if(tmp.left!=null) queue.add(tmp.left);
                if(tmp.right!=null) queue.add(tmp.right);
                ave+=tmp.val;
            }
            res.add(ave*1.0/size);
            size = queue.size();
        }
        return res;
        
    }
    }
}