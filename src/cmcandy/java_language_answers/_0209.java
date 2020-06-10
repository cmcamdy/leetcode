package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/6/10.
 */
public class _0209 {
    static class Solution {
        public int minSubArrayLen(int s, int[] nums) {

            //滑动窗口left、right，并记录滑动过程中最长长度即可
            //窗口扩张：<s
            //窗口收缩：>s
            if (nums.length < 1) return 0;
            int right = 0;
            int left = 0;
            int min_len = Integer.MAX_VALUE;
            int sum = 0;

            while (right <= nums.length) {
                //如果sum<s,扩张
                if (sum < s&&right<nums.length) {
                    sum += nums[right++];
                } else {
                    if (sum>=s){
                        //如果sum>=s 收缩
                        sum -= nums[left++];
                    }else break;
                }
                if (sum >= s) {
                    min_len = Math.min(min_len, right - left);
                }
            }
            return min_len==Integer.MAX_VALUE?0:min_len;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.minSubArrayLen(11, new int[]{1, 2, 3, 4, 5}));
        System.out.println(solution.minSubArrayLen(4, new int[]{1, 4, 4}));
//        System.out.println(solution.minSubArrayLen(7, new int[]{2, 3, 1, 2, 4, 3}));
    }
}
