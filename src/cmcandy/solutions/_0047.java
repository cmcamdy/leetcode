package cmcandy.solutions;

import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * Created by CHEN on 2020/5/15.
 */
public class _0047 {
    static class Solution {
        private HashMap<Integer,Integer> hashMap = new HashMap<>();
        public List<List<Integer>> permuteUnique(int[] nums) {
            ArrayList<Integer> list = new ArrayList<>();
            for(int i =0;i<nums.length;i++){
                list.add(nums[i]);
            }
            List<List<Integer>> res = new ArrayList<>();
            DFS(res,list,new ArrayList<>());
            return res;
        }

        public void DFS(List<List<Integer>> res,List<Integer> nums,ArrayList<Integer> arrange){
            if (nums.size()==0){
                ArrayList<Integer> tmp = new ArrayList<>();
                tmp.addAll(arrange);
                if (!res.contains(tmp))
                res.add(tmp);
                return;
            }

            List tmp = new ArrayList();
            tmp.addAll(nums);
            for (int i =0;i<nums.size();i++){
                arrange.add(nums.get(i));
                tmp.remove(i);
                DFS(res,tmp,arrange);
                tmp.add(i,nums.get(i));
//                tmp.clear();
//                tmp.addAll(nums);
                arrange.remove(arrange.size()-1);
            }
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.permuteUnique(new int[]{1,1,2});
        Arrays.asList(new int[]{1,1,2});
        System.out.println( "aaa");
    }
}
