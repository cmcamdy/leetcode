package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/10.
 */
public class _0053 {
    static class Solution {
        public int maxSubArray(int[] nums) {
            //贪心算法和动态规划
            //这里是动态规划

            //获取数组长度
            int len = nums.length;
            int[] tmp = new int[len];
            int max = nums[0];

            tmp[0] = nums[0];
            for(int i = 1;i<=len-1;i++){
                if(tmp[i-1]>0) tmp[i] = nums[i]+tmp[i-1];
                else tmp[i] =nums[i];
                if (max<tmp[i])max=tmp[i];
            }
            return max;
        }
    }
}
