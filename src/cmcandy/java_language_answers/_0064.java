package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/18.
 */
public class _0064 {
    static class Solution {
        public int minPathSum(int[][] grid) {
            //动态规划
            int row = grid.length;
            if(row<1) return 0;
            int col = grid[0].length;
            if(row == 1&&col == 1) return grid[0][0];

            //记录最短路径的数组
            //init
            int[][] tmp = new int[row][col];
            tmp[0][0] = grid[0][0];
            for(int i = 1;i<row;i++){
                tmp[i][0] = grid[i][0]+tmp[i-1][0];
            }
            for(int i = 1;i<col;i++){
                tmp[0][i] = grid[0][i]+tmp[0][i-1];
            }

            for(int i = 1;i<row;i++){
                for(int j =1;j<col;j++){
                    tmp[i][j] = grid[i][j]+Math.min(tmp[i][j-1],tmp[i-1][j]);
                }
            }
            return tmp[row-1][col-1];

        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.minPathSum(new int[][]{{9,1,4,8}}) );
    }
}
