package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/10.
 */
public class _0122 {
    static class Solution {
        public int maxProfit(int[] prices) {

            //不能同时参与多场交易，可以不同时间参与多场交易

            //采用贪心，计算每个谷峰的和

            int sum = 0;
            for(int i = 1;i<prices.length;i++){
                //如果i>i-1的值，则说明曲线上升，则不是峰谷
                //核心就是计算每个上升差值即可
                if(prices[i]>prices[i-1]) sum +=prices[i]-prices[i-1];
            }

            return sum;

        }
    }
}
