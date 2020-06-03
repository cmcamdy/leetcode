package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/6.
 */
public class _0027 {
    static class Solution {
        public int removeElement(int[] nums, int val) {
            int tmp = nums[0];
            int index = 0;
            for(int i = 1;i<nums.length;i++){
                if(nums[i] != val){
                    nums[index++]=nums[i];
                }
            }
            nums[index] = tmp;
            return tmp==val?index:index+1;
        }
    }


    public static void main(String[] args) {
        Solution solution  = new Solution();
        System.out.println(solution.removeElement(new int[]{0,1,2,2,3,0,4,2},2) );
    }
}
