package cmcandy.Java_Language_Answers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by CHEN on 2020/4/12.
 */
public class _0015 {

    /**
     * 三数之和
     * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
     * 注意：答案中不可以包含重复的三元组。
     * 示例：
     * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
     * 满足要求的三元组集合为：
     * [
     * [-1, 0, 1],
     * [-1, -1, 2]
     * ]
     */
    static class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            //排序
            Arrays.sort(nums);
            List<List<Integer>> ans = new ArrayList( );
            int right, left;
            for (int i = 0; i < nums.length - 2; i++) {
                if ((i >= 1 && nums[i - 1] == nums[i])) continue;
                if (nums[i] > 0) break;
                right = nums.length - 1;
                left = i + 1;
                while (right > left) {
                    if (nums[right] + nums[i] + nums[left] > 0) {
                        right--;
                    } else if (nums[right] + nums[i] + nums[left] < 0) {
                        left++;
                    } else if (nums[right] + nums[i] + nums[left] == 0) {
                        //可以匹配
                        ans.add(Arrays.asList(nums[i], nums[left], nums[right]));
                        while (left < right && nums[left] == nums[left + 1]) left++; // 去重
                        while (left < right && nums[right] == nums[right - 1]) right--; // 去重
                        right--;
                        left++;
                    }
                }
            }
            return ans;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.threeSum(new int[]{0, 0, 0, 0}));
        System.out.println(solution.threeSum(new int[]{-1, 0, 1, 0}));
        System.out.println(solution.threeSum(new int[]{-1, 0, 1, 2, -1, -4}));
        System.out.println(solution.threeSum(new int[]{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6}));
    }


}
