package cmcandy.solutions;

import java.util.Arrays;

public class _0611 {
    static class Solution {
        public int triangleNumber(int[] nums) {
            int len = nums.length;
            if (len < 3)
                return 0;
            Arrays.sort(nums);
            int num = 0;

            int itimes = 0;
            int jtimes = 0;
            int tim_jtimes = 0;

            for (int i = 0; i < len - 2; i++) {
                if (nums[i] == 0)
                    continue;
                else {
                    for (int j = i + 1; j < len - 1; j++) {
                        if (nums[j] == 0)
                            continue;
                        if (j > i + 1 && nums[j] == nums[j - 1]) {
                            tim_jtimes = jtimes;
                            num += --jtimes;
                        } else {
                            jtimes = 0;
                            for (int k = j + 1; k < len; k++) {
                                if (isTri(nums[i], nums[j], nums[k])) {
                                    jtimes++;
                                    num++;
                                } else
                                    continue;
                            }
                        }
                    }
                }
            }
            return num;
        }
        public boolean isTri(int b1, int b2, int b3) {
            return (b1 + b2 <= b3 || b2 + b3 <= b1 || b1 + b3 <= b2) ? false : true;
        }

    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.triangleNumber(new int[] { 19, 26, 26, 26, 80, 92, 77 }));
        System.out.println(solution.triangleNumber(new int[] { 0, 1, 1, 1 }));
        System.out.println(solution.triangleNumber(new int[] { 2, 2, 2, 3 }));
    }
}