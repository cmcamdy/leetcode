package cmcandy.Java_Language_Answers;

public class _0643 {
    static class Solution {
        public double findMaxAverage(int[] nums, int k) {
    
            //滑动窗口法
            int len = nums.length;
            if(len<1) return 0;
            int sum = 0;
            //init
            for(int i =0 ;i<k;i++){
                sum+=nums[i];
            }
            int max = sum;
            for(int i = k;i<len;i++){
                sum=sum-nums[i-k]+nums[i];
                if(max<sum) max = sum;
            }
            return max*1.0/k;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.findMaxAverage(new int[]{1,12,-5,-6,50,3}, 4));
    }
}