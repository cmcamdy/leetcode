package cmcandy.java_language_answers;

import java.util.Arrays;

/**
 * Created by CHEN on 2020/5/6.
 */
public class _0031 {
    static class Solution {
        public void nextPermutation(int[] nums) {
            //降序遍历,找到第一个后者>前者的位置x，以此为轴，找到后方<=x且>x-1的值，交换即可，x后边应当变为升序
            int len = nums.length;
            int j;
            boolean jud = false;
            if (len <= 1) return;
            if (len == 2) {
                change(nums, 0, 1);
                return;
            }
            for (int i = len - 1; i >= 0; i--) {
                if (nums[i] > nums[i - 1]) {
                    //[i,len-1]中找出一个比i-1大的最少的数
                    if (i == len - 1) {
                        change(nums, i - 1, i);
                        return;
                    }
                    j = i + 1;
                    for (; j < len; j++) {
                        if (nums[j] <= nums[i - 1]) {
                            //找到，交换
                            change(nums, i - 1, j - 1);
                            //然后排序，接着break
                            Arrays.sort(nums, i, len);
                            return;
                        }
                    }
                    change(nums, i - 1, len - 1);
                    Arrays.sort(nums, i, len);
                    return;
                }
            }
            Arrays.sort(nums);
        }

        public void change(int[] nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        solution.nextPermutation(new int[]{1, 3, 2});
        solution.nextPermutation(new int[]{1, 5, 1});
    }
}
