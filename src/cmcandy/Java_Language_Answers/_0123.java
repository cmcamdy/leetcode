package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/10.
 */
public class _0123 {
    static class Solution {
        public int maxProfit(int[] prices) {
            //https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/

            int n = prices.length;
            if(n==0)return 0;
            int max_k = 2;
            int[][][] dp = new int[n][max_k + 1][2];
            for (int i = 0; i < n; i++) {
                for (int k = max_k; k >= 1; k--) {
                    if (i - 1 == -1) {
                        dp[0][k][0] = 0;
                        dp[0][k][1] = -prices[i];
                    }else{
                        dp[i][k][0] = Math.max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                        dp[i][k][1] = Math.max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
                    }}
            }
            // 穷举了 n × max_k × 2 个状态，正确。
            return dp[n - 1][max_k][0];




        }
    }

    public static void main(String[] args) {
        Solution[] solutions = new Solution[14];
        solutions[0] = new Solution();
        Solution solution = new Solution();
    }
}
