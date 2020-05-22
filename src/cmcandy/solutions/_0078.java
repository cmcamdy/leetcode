package cmcandy.solutions;

import java.util.Arrays;
import java.util.LinkedList;
/**
 * Created by CHEN on 2020/5/22.
 */
import java.util.List;

public class _0078 {

    static class Solution {

        private List<List<Integer>> output = new LinkedList<>();
        private int len = 0;

        public List<List<Integer>> subsets(int[] nums) {

            this.len = nums.length;
            //基本情况排除
            if (len <= 1) {
                output.add(new LinkedList<>());
                if(len ==1){
                    output.add(Arrays.asList(nums[0]));
                }
                return output;
            }

            // 循环(0,nums.length),计算i开头的子集
            add(nums, 0, new LinkedList<>(), len);
            return output;
        }

        public void add(int[] nums, int start, LinkedList<Integer> list, int k) {

            output.add(new LinkedList<>(list));
            if (k > 1) {
                // 进入下一轮循环
                for (int i = start; i < this.len; i++) {
                    list.add(nums[i]);
                    add(nums, i+1, list, k );
                    list.removeLast();
                    k--;
                }
            }
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.subsets(new int[] { 0 }));

        System.out.println(solution.subsets(new int[] { 1, 2, 3 }));
    }
}