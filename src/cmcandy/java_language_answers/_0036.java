package cmcandy.java_language_answers;

import java.util.HashMap;

/**
 * Created by CHEN on 2020/5/9.
 */
public class _0036 {
    static class Solution {
        public boolean isValidSudoku(char[][] board) {
            //输入为9x9
            HashMap<Character, Integer> hashMap = new HashMap( );
            HashMap<Character, Integer> hashMap2 = new HashMap( );
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] <= 57 && board[i][j] >= 49) {
                        if (hashMap.isEmpty()||hashMap.get(board[i][j]) == null) hashMap.put(board[i][j], 1);
                        else return false;
                    }
                    if (board[j][i] <= 57 && board[j][i] >= 49) {
                        if (hashMap2.isEmpty()||hashMap2.get(board[j][i]) ==null) hashMap2.put(board[j][i], 1);
                        else return false;
                    }
                }
                hashMap.clear( );
                hashMap2.clear( );
            }

            for (int k = 0; k <= 6; k += 3) {
                for (int t = 0; t <= 6; t += 3) {
                    for (int i = k; i < k + 3; i++) {
                        for (int j = t; j < t + 3; j++) {
                            if (board[i][j] <= 57 && board[i][j] >= 49) {
                                if (hashMap.get(board[i][j]) == null) hashMap.put(board[i][j], 1);
                                else return false;
                            }
                        }

                    }
                    hashMap.clear( );
                }

            }
            return true;
        }
    }

    public static void main(String[] args) {

        char[][] a = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
        Solution solution = new Solution();
        System.out.println(solution.isValidSudoku(a) );
    }
}
