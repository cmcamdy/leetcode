package cmcandy.java_language_answers;
/**
 * Created by CHEN on 2020/5/24.
 */
public class _0080 {
    class Solution {
        public int removeDuplicates(int[] nums) {
            int len = nums.length;
            if (len<3) return len;
            int num = nums[0];
            int times = 1;
            int length = 1;
            int index = 1;
            for(int i = 1;i<nums.length;i++){
                if(nums[i]==num){
                    times+=1;
                    if(times<=2) {
                        length++;
                        nums[index] = nums[i];
                        index++;
                    }
                }else if(nums[i]!=num){
                    num = nums[i];
                    times = 1;
                    nums[index] = nums[i];
                    index++;
                    length++;
                }
            }
            return length;
        }
    } 
}