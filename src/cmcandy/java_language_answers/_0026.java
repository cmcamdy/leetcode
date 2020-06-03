package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/6.
 */
public class _0026 {

    static class Solution {
        public int removeDuplicates(int[] nums) {
            int index = 0;
            for(int i = 1 ; i < nums.length ; i++){
                if(nums[index]!=nums[i]){
                    index++;
                    nums[index] = nums[i];
                }
            }
            return index+1;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.removeDuplicates(new int[]{1,1,2}) );
    }
}
