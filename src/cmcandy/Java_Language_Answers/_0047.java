package cmcandy.Java_Language_Answers;

import java.util.*;
import java.util.List;

/**
 * Created by CHEN on 2020/5/15.
 */
public class _0047 {
    static class Solution {
        public List<List<Integer>> permuteUnique(int[] nums) {
            List<List<Integer>> res = new ArrayList<>( );
            Arrays.sort(nums);
            DFS(res, nums, new ArrayDeque<>( ), new boolean[nums.length]);
            return res;
        }

        public void DFS(List<List<Integer>> res, int[] nums, Deque<Integer> arrange, boolean[] isVisited) {
            if (nums.length == arrange.size( )) {
                if (!res.contains(arrange))
                res.add(new ArrayList<>(arrange));
                return;
            }

            for (int i = 0; i < nums.length; i++) {
                //访问过
                if (!isVisited[i]) {
                    //第一个，或者相同但是前一个被访问过，或者不同
                    if (i == 0 || (nums[i]==nums[i-1]&&isVisited[i - 1])||nums[i]!=nums[i-1]) {
                        arrange.add(nums[i]);
                        isVisited[i] = true;
                        DFS(res, nums, arrange, isVisited);
                        arrange.removeLast( );
                        isVisited[i] = false;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        solution.permuteUnique(new int[]{3,3,0,3});
        Arrays.asList(new int[]{1, 1, 2});
        System.out.println("aaa");
    }
}
