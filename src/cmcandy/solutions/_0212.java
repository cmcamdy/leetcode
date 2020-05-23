package cmcandy.solutions;

import java.util.*;

public class _0212 {
    static class Solution {
        private int[][] tmp;
        private char[][] board;
        private String word;
        private int row;
        private int col;
        LinkedList<String> output = new LinkedList<>();

        public List<String> findWords(char[][] board, String[] words) {

            this.row = board.length;
            if (this.row < 1)
                return output;
            this.col = board[0].length;

            this.board = board;
            // 从每格开始当头匹配
            loop1: for (int k = 0; k < words.length; k++) {
                this.word = words[k];
                tmp = new int[row][col];
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        // 如果找到了，那么就进入下一个循环
                        if (backtrack(i, j, 0))
                            continue loop1;
                    }
                }
            }
            return output;
        }

        public boolean backtrack(int i, int j, int k) {

            if (board[i][j] == word.charAt(k)) {
                if (k == word.length() - 1) {
                    output.add(word);
                    return true;
                }
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
        System.out.println(solution.findWords(new char[][]{{'a','b'},{'c','d'}},new String[]{"ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"}));
        System.out.println(solution.findWords(new char[][]{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}},new String[]{"oath","pea","eat","rain"}));
    }
}