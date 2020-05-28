package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/22.
 */
import java.util.List;
import java.util.LinkedList;
import java.util.Arrays;

public class _0090 {

    static class Solution {

        private List<List<Integer>> output = new LinkedList<>();
        private int len = 0;

        public List<List<Integer>> subsetsWithDup(int[] nums) {
            this.len = nums.length;
            Arrays.sort(nums);
            // 基本情况排除
            if (len <= 1) {
                output.add(new LinkedList<>());
                if (len == 1) {
                    output.add(Arrays.asList(nums[0]));
                }
                return output;
            }

            // 循环(0,nums.length),计算i开头的子集
            add(nums, 0, new LinkedList<>(), len);
            return output;
        }

        public void add(int[] nums, int start, LinkedList<Integer> list, int k) {
            if (!output.contains(list))
                output.add(new LinkedList<>(list));
            if (k > 1) {
                // 进入下一轮循环
                for (int i = start; i < this.len; i++) {
                    if ((k == this.len && i > 1 && nums[i] == nums[i - 1])) {
                        k--;
                        continue;
                    }
                    list.add(nums[i]);
                    add(nums, i + 1, list, k-1  );
                    list.removeLast();
                    k--;
                }
            }
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.subsetsWithDup(new int[] { 1,2,2 }));
    }

}