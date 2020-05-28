package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/11.
 */
public class _0063 {
    static class Solution {
        public int uniquePathsWithObstacles(int[][] obstacleGrid) {
            if(obstacleGrid[0][0]==1) return 0;
            //列数
            int m = obstacleGrid[0].length;
            //行数
            int n = obstacleGrid.length;

            int[][] tmp = new int[n+1][m+1];
            //首先走边界肯定只有一种路径，因此上、左两边的值可以直接初始化
            for (int i = 0;i<n;i++){
                if(obstacleGrid[i][0] == 1){
                    break;
                }else{
                    tmp[i+1][1] = 1;
                }}
            for(int j = 1;j<m;j++){
                if(obstacleGrid[0][j]==1){
                    break;
                }else{
                    tmp[1][j+1] = 1;
                }}
            for(int i = 1;i<n;i++){
                for(int j = 1;j<m;j++){
                    if(obstacleGrid[i][j]==1) tmp[i+1][j+1]=0;
                    else{
                        //值=上左两格的值的和
                        tmp[i+1][j+1] = tmp[i][j+1]+tmp[i+1][j];
                    }}
            }
            return tmp[n][m];

        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.uniquePathsWithObstacles(new int[][]{{0,0,0},{0,1,0},{0,0,0}}) );
    }


}
