package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/10.
 */
public class _0188 {
    static class Solution {
        public int maxProfit(int k, int[] prices) {
            int n = prices.length;
            if(n==0)return 0;
            //k>长度的一半的时候，k就不存在意义，直接套用122的代码
            if (k > n / 2)
                return maxProfit_k_inf(prices);
            int[][][] dp = new int[n][k + 1][2];
            for (int i = 0; i < n; i++) {
                for (int j = k; j >= 1; j--) {
                    if (i - 1 == -1) {
                        dp[0][j][0] = 0;
                        dp[0][j][1] = -prices[i];
                    }else{
                        dp[i][j][0] = Math.max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                        dp[i][j][1] = Math.max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
                    }}
            }
            // 穷举了 n × max_k × 2 个状态，正确。
            return dp[n - 1][k][0];
        }
        public int maxProfit_k_inf(int[] prices) {

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
