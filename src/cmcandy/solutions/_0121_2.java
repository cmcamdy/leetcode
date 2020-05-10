package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/10.
 */
public class _0121_2 {
    static class Solution {
        public int maxProfit(int[] prices) {

            //贪心或者动态

            //这里是贪心

            //数组长度
            int len = prices.length;
            //没有输入则看作没有交易发生，返回0
            if(len==0) return 0;
            //差值最大值
            int max = 0;
            int tmp = 0;

            for(int i = 1;i<len;i++){
                //如果当前利润大于0，则加上i-(i-1)的两个差的值
                if(tmp>0) tmp = prices[i]-prices[i-1]+tmp;
                else if(tmp<=0) tmp = prices[i]-prices[i-1];

                if(max<tmp) max = tmp;
            }
            return max;
        }
    }
}
