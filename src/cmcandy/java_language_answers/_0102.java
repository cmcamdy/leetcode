import java.util.LinkedList;
import java.util.List;
public class _0102 {
    /**
     * Definition for a binary tree node. public class TreeNode { int val; TreeNode
     * left; TreeNode right; TreeNode(int x) { val = x; } }
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
        public List<List<Integer>> levelOrder(TreeNode root) {
            // 层序
            int size = 1;
            TreeNode tmp;
            //利用队列来实现层序遍历
            LinkedList<TreeNode> list = new LinkedList<>(); 
            List<List<Integer>> res = new LinkedList<>();
            if(root==null) return res;
            list.add(root);
            while(list.size()>0){
                //开始遍历
                List<Integer> nums = new LinkedList<>();
                size = list.size();
                for(int i =0;i<size;i++){
                    tmp = list.removeFirst();
                    //如果还有下一层，那就入队
                    if(tmp.left!=null) {list.add(tmp.left);}
                    if(tmp.right!=null) {list.add(tmp.right);}
                    nums.add(tmp.val);
                }
                res.add(nums);
            }
            return res;
        }
    }
}