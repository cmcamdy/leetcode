package cmcandy.java_language_answers;

import java.util.List;
import java.util.ArrayList;

/**
 * Created by CHEN on 2020/5/14.
 */
public class _0046 {

    static class Solution {
        public List<List<Integer>> permute(int[] nums) {
            List<List<Integer>> res = new ArrayList<>();
            DFS(res,nums,new ArrayList<>());
            return res;
        }

        public void DFS(List<List<Integer>> res,int[] nums,List<Integer> isVisited){

            if (isVisited.size()==nums.length){
                ArrayList<Integer> tmp = new ArrayList<>();
                tmp.addAll(isVisited);
                res.add(tmp);
                return;
            }
            for(int i =0;i<nums.length;i++){
                //如果i位置的元素被没被访问过
                if (isVisited.indexOf(nums[i])==-1){
                    isVisited.add(nums[i]);
                    DFS(res,nums,isVisited);
                    isVisited.remove(isVisited.size()-1);
                }
            }
        }
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.permute(new int[]{1,2,3});
    }
}
