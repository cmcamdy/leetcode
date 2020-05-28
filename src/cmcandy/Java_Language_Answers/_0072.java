package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/20.
 */
public class _0072 {

    static class Solution {
        public int minDistance(String word1, String word2) {

            int row = word1.length( );
            int col = word2.length( );
            if (row < 1) return col;
            if (col < 1) return row;
            int[][] res = new int[row + 1][col + 1];
            res[0][0] = 0;
            for (int i = 1; i < row + 1; i++) {
                res[i][0] = i;
            }
            for (int j = 1; j < col + 1; j++) {
                res[0][j] = j;
            }

            for (int i = 1; i < row + 1; i++) {
                for (int j = 1; j < col + 1; j++) {
                    //如果word1[i]==word2[j]
                    if (word1.charAt(i - 1) == word2.charAt(j - 1)) res[i][j] = res[i - 1][j - 1];
                        //如果word1[i]!=word2[j]
                    else if (word1.charAt(i - 1) != word2.charAt(j - 1))
                        res[i][j] = Math.min(Math.min(res[i - 1][j - 1], res[i][j - 1]), res[i - 1][j]) + 1;
                }
            }
            return res[row][col];
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.minDistance("horse", "ros"));
    }
}
