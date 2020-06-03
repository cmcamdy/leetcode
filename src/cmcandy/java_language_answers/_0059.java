package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/16.
 */
public class _0059 {
    static class Solution {
        public int[][] generateMatrix(int n) {

            int[][] matrix = new int[n][n];
            int tmp = 1;
            int rowstart = 0;
            int culstart = 0;
            int rowend = n - 1;
            int culend = n - 1;
            while (culstart < culend && rowstart < rowend) {
                //→
                for (int i = culstart; i <= culend; i++) {
                    matrix[rowstart][i] = tmp++;

                }
                rowstart++;
                //↓
                for (int j = rowstart; j <= rowend; j++) {
                    matrix[j][culend] = tmp++;
                }
                culend--;
                //←
                for (int i = culend; i >= culstart; i--) {
                    matrix[rowend][i] = tmp++;
                }
                rowend--;
                //↑
                for (int j = rowend; j >= rowstart; j--) {
                    matrix[j][culstart] = tmp++;
                }
                culstart++;
            }
            //排除基本情况n==2的时候
            if (n * n + 1 > tmp)
                matrix[rowstart][culstart] = tmp++;
            return matrix;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.generateMatrix(2));
        System.out.println(solution.generateMatrix(3));
        System.out.println(solution.generateMatrix(4));
        System.out.println(solution.generateMatrix(6));
    }
}
