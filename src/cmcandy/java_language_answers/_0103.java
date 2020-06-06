package cmcandy.java_language_answers;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by CHEN on 2020/6/7.
 */
public class _0103 {


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
          TreeNode(int x) { val = x; }
      }
    class Solution {
        public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

            LinkedList<TreeNode> queue = new LinkedList<>();
            queue.add(root);
            int tag = 0;
            int len = 1;
            int count = 0;
            TreeNode tmpNode;
            LinkedList<List<Integer>> res = new LinkedList<>();
            if(root==null) return res;
            while(!queue.isEmpty()){
                LinkedList<Integer> tmp  = new LinkedList<>();
                if(tag==0){
                    for(int i = 0; i < len; i++){

                        tmpNode = queue.removeLast();
                        if(tmpNode.left!=null) queue.add(count++,tmpNode.left);
                        if(tmpNode.right!=null) queue.add(count++,tmpNode.right);
                        tmp.add(tmpNode.val);
                    }
                    tag = 1;
                }
                else{
                    for(int i = 0; i < len; i++){
                        tmpNode = queue.removeLast();
                        if(tmpNode.right!=null) queue.add(count++,tmpNode.right);
                        if(tmpNode.left!=null) queue.add(count++,tmpNode.left);
                        tmp.add(tmpNode.val);
                    }
                    tag = 0;
                }
                count = 0;
                len = queue.size();
                res.add(tmp);
            }
            return res;
        }
    }
}
