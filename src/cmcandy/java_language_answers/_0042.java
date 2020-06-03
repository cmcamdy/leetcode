package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/14.
 */
public class _0042 {

    static class Solution {
        public int trap(int[] height) {

            int len = height.length;
            if (len < 3) return 0;
            int max = 0;
            int sum = 0;
            //动态规划，从左往右的最大值
            int[] left = new int[len];
            //从右往左的最大值
            int[] right = new int[len];

            for (int i = 0; i < len; i++) {
                if (height[i] > max) max = height[i];
                left[i] = max;
            }
            max = 0;
            for (int i = len - 1; i >= 0; i--) {
                if (height[i] > max) max = height[i];
                right[i] = max;
            }
            //两边取最小值计算和height的差值，即可找到该块的积水量
            for (int i = 0; i < len; i++) {
                int tmp = Math.min(left[i], right[i]);
                sum += tmp - height[i];
            }
            return sum;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.trap(new int[]{0,1,0,2,1,0,1,3,2,1,2,1} ) );
    }

}
