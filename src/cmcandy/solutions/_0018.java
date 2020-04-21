package cmcandy.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by CHEN on 2020/4/20.
 */
public class _0018 {
    static class Solution {
        public List<List<Integer>> fourSum(int[] nums, int target) {

            //排序
            Arrays.sort(nums);
            List<List<Integer>> ans = new ArrayList( );
            int right, left;
            for (int j = 0; j < nums.length - 3; j++) {
                if ((j >= 1 && nums[j - 1] == nums[j])) continue;
//                if (nums[j] > target) break;
                for (int i = j + 1; i < nums.length - 2; i++) {
                    if ((i > j + 1 && nums[i - 1] == nums[i]))
                        continue;
                    right = nums.length - 1;
                    left = i + 1;
                    while (right > left) {
                        if (nums[j] + nums[right] + nums[i] + nums[left] > target) {
                            right--;
                        } else if (nums[j] + nums[right] + nums[i] + nums[left] < target) {
                            left++;
                        } else if (nums[j] + nums[right] + nums[i] + nums[left] == target) {
                            //可以匹配
                            ans.add(Arrays.asList(nums[j], nums[i], nums[left], nums[right]));
                            while (left < right && nums[left] == nums[left + 1]) left++; // 去重
                            while (left < right && nums[right] == nums[right - 1]) right--; // 去重
                            right--;
                            left++;
                        }
                    }
                }
            }
            return ans;

        }

    }

    public static void main(String[] args) {
        //

        Solution solution = new Solution( );
        System.out.println(solution.fourSum(new int[]{1,-2,-5,-4,-3,3,3,5}, -11));
    }
}
