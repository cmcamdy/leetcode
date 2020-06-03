package cmcandy.java_language_answers;
/**
 * Created by CHEN on 2020/5/23.
 */
public class _0079 {
    static class Solution {
        private int[][] tmp;
        private char[][] board;
        private String word;
        private int row;
        private int col;

        public boolean exist(char[][] board, String word) {
            // 回朔法，像走迷宫

            this.row = board.length;
            if (this.row < 1)
                return false;
            this.col = board[0].length;

            this.word = word;
            this.board = board;
            this.tmp = new int[row][col];
            // 从每格开始当头匹配
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {

                    if (backtrack(i, j, 0))
                        return true;

                }
            }

            return false;

        }

        public boolean backtrack(int i, int j, int k) {

            if (board[i][j] == word.charAt(k)) {
                if(k == word.length()-1) return true;
                // next turn 上下左右寻找
                tmp[i][j] = 1;
                if (i > 0 && tmp[i - 1][j] == 0 && backtrack(i - 1, j, k + 1)) {
                    return true;
                } else if (i < row - 1 && tmp[i + 1][j] == 0 && backtrack(i + 1, j, k + 1)) {
                    return true;
                } else if (j > 0 && tmp[i][j - 1] == 0 && backtrack(i, j - 1, k + 1)) {
                    return true;
                } else if (j < col - 1 && tmp[i][j + 1] == 0 && backtrack(i, j + 1, k + 1)) {
                    return true;
                }
                tmp[i][j] = 0;
            }
            return false;
        }

    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.exist(new char[][]{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}, "ABCCED"));
    }
}