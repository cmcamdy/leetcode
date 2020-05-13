package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/11.
 */
public class _0062 {
    static class Solution {
        public int uniquePaths(int m, int n) {
            //排列组合


            //这里用动态规划,类似与楼梯问题
            int[][] tmp = new int[n+1][m+1];

            //init
            //首先走边界肯定只有一种路径，因此上、左两边的值可以直接初始化
            for (int i = 1;i<=n;i++){
                tmp[i][1] = 1;
            }
            for(int j = 2;j<=m;j++){
                tmp[1][j] = 1;
            }

            for(int i = 2;i<=n;i++){
                for(int j = 1;j<=m;j++){
                    //值=上左两格的值的和
                    tmp[i][j] = tmp[i-1][j]+tmp[i][j-1];
                }
            }
            return tmp[n][m];
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.uniquePaths(3,2) );
    }
}
