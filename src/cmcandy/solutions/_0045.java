package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/14.
 */
public class _0045 {

    static class Solution {
        public int jump(int[] nums) {

            int max = 0;
            int len = nums.length;
            if (len <= 1) return 0;
            int time = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] + i >= len - 1) return time + 1;
                max = i + 1;
                for (int j = 1; j <= nums[i]; j++) {
                    if (nums[j + i]+j+i >=nums[max]+max) max = i + j;
                }
                i = max - 1;
                time++;
            }
            return time + 1;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.jump(new int[]{1, 2, 1, 1, 1}));
    }
}
