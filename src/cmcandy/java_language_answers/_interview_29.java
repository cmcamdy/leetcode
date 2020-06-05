package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/6/5.
 */
public class _interview_29 {
    static class Solution {
        public int[] spiralOrder(int[][] matrix) {
            int i = 0;
            int j = 0;
            int row = matrix.length;
            if (row < 1) return new int[0];
            int col = matrix[0].length;
            int total = row * col;
            int[] res = new int[total];
            int index = 0;
            int cycle = 0;
            while (index < total) {
                for (; j < col - cycle; j++) res[index++] = matrix[i][j];
                if (index == total) break;
                i++;
                j--;
                for (; i < row - cycle; i++) res[index++] = matrix[i][j];
                if (index == total) break;
                j--;
                i--;
                for (; j >= 0 + cycle; j--) res[index++] = matrix[i][j];
                if (index == total) break;
                i--;
                j++;
                for (; i > 0 + cycle; i--) res[index++] = matrix[i][j];
                j++;
                i++;
                cycle++;
            }
            return res;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        solution.spiralOrder(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
        solution.spiralOrder(new int[][]{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});
        String.valueOf(1).substring(1);

    }
}
