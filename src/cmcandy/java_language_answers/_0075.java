package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/20.
 */
public class _0075 {
    static class Solution {
        public void sortColors(int[] nums) {
            // Arrays.sort(nums);
            int right = nums.length-1;
            int left = 0;
            int cur = 0;
            while(cur<=right){
                if(nums[cur]==0){
                    nums[cur++] = nums[left];
                    nums[left++] =0;
                }
                else if(nums[cur] ==2){
                    nums[cur] = nums[right];
                    nums[right--] = 2;
                }else if(nums[cur] ==1){
                    cur++;
                }
            }
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.sortColors(new int[]{2,0,2,1,1,0});
        solution.sortColors(new int[]{2,0,1});
    }
}
