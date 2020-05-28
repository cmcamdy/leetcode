package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/9.
 */
public class _0034 {
    static class Solution {
        public int[] searchRange(int[] nums, int target) {
            //二分+左右扩张
            if (nums.length == 0 || nums[nums.length - 1] < target || nums[0] > target) return new int[]{-1, -1};
            if (nums.length == 1) return nums[0] == target ? new int[]{0, 0} : new int[]{-1, -1};
            int start = 0;
            int end = nums.length - 1;
            int mid = 0;

            if (nums[0] == target) {
                mid = 0;
            } else if (nums[nums.length - 1] == target) {
                mid = nums.length - 1;
            } else if (nums[nums.length - 1] != target) {
                while (start < end - 1) {
                    mid = (start + end) / 2;
                    if (nums[mid] > target) {
                        end = mid;
                    } else if (nums[mid] < target) {
                        start = mid;
                    } else if (nums[mid] == target) {
                        break;
                    }
                }
            }


            if (nums[mid] != target) return new int[]{-1, -1};
                //拿到了相等的那个值
            else if (nums[mid] == target) {
                int right = mid;
                int left = mid;
                while (left >= 1 && nums[left - 1] == target) {
                    left--;
                }
                while (right < nums.length - 1 && nums[right + 1] == target) {
                    right++;
                }
                return new int[]{left, right};
            }
            return new int[]{-1, -1};
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.searchRange(new int[]{5, 7, 7, 8, 8, 10}, 8));
        System.out.println(solution.searchRange(new int[]{1, 4}, 4));
        System.out.println(solution.searchRange(new int[]{1, 2, 3}, 1));
    }
}
