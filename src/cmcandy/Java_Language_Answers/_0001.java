package cmcandy.Java_Language_Answers;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by CHEN on 2020/4/3.
 */
public class _0001 {

    static class Solution {
        public int[] twoSum(int[] nums, int target) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                int complement = target - nums[i];
                if (map.containsKey(complement)) {
                    return new int[] { map.get(complement), i };
                }
                map.put(nums[i], i);
            }
            return null;
        }
    }
    public static void main(String[] args) {

    }
}
