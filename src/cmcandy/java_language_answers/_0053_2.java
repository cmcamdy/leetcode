package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/10.
 */
public class _0053_2 {

    static class Solution {
        public int maxSubArray(int[] nums) {
            //贪心算法和动态规划

            //这里是贪心算法
            //获取数组长度
            int len = nums.length;
            int max = nums[0];
            int tmp = max;
            for(int i = 1;i<=len-1;i++){
                //如果之前的数小于0，抛弃
                if(tmp<=0)tmp = nums[i];
                    //如果之前的数大于0，加上
                else if(tmp>0) tmp+=nums[i];
                //判断，是否更新max
                if(max<tmp)max = tmp;
            }

            return max;
        }
    }
}
