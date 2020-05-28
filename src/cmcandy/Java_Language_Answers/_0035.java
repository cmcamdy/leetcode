package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/7.
 */
public class _0035 {

    static class Solution {
        public int searchInsert(int[] nums, int target) {
            if (nums[0]>target) return 0;
            if (nums[nums.length-1]<target) return nums.length;
            return search(nums, 0, nums.length - 1, target);
        }

        public int search(int[] nums, int first, int last, int target) {
            int mid = (first + last) / 2;
            if (first==last-1){
                if (nums[first]==target)return first;
                else if (nums[last]==target) return  last;
                else return last;
            }
            if (nums[mid] > target) return search(nums, first, mid, target);
            else if (nums[mid] < target) return search(nums, mid, last, target);
            else if (nums[mid] == target) return mid;
            return -1;
        }
    }
}
