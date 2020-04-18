package cmcandy.solutions;

import java.util.Arrays;

/**
 * Created by CHEN on 2020/4/12.
 */
public class _0016 {
    static class Solution {
        public int threeSumClosest(int[] nums, int target) {
            //排序
            Arrays.sort(nums);
            int min = Integer.MAX_VALUE;
            int right, left;
            for (int i = 0; i < nums.length - 2; i++) {
                if ((i >= 1 && nums[i - 1] == nums[i])) continue;
                if (nums[i] > 0) break;
                right = nums.length - 1;
                left = i + 1;
                while (right > left) {
                     if (nums[right] + nums[i] + nums[left] <min ) {
                        //可以匹配
                        min = nums[right] + nums[i] + nums[left];
                        while (left < right && nums[left] == nums[left + 1]) left++; // 去重
                        while (left < right && nums[right] == nums[right - 1]) right--; // 去重
                        right--;
                        left++;
                    }
                }
            }
            return min;
        }
    }
}
