package cmcandy.solutions;

import java.util.HashMap;

/**
 * Created by CHEN on 2020/5/18.
 */
public class _0037 {
    static class Solution {
        //27个hashmap，9个一组，分为横、竖、块
        private HashMap<Character, Integer>[] col = new HashMap[9];
        private HashMap<Character, Integer>[] row = new HashMap[9];
        private HashMap<Character, Integer>[] chunk = new HashMap[9];

        public void solveSudoku(char[][] board) {
            //1、读取原本存在的数，每一次读取都有三个hashMap需要放,遍历一遍即可
            //  横着：  j+1
            //  竖着：  i+1
            //  块：    (j/3)*3+(i/3)+1
            initHash(board);
            //2、回朔法：递归？如果此值满足取值条件但是走不下去，则返回取下一个值，取值范围就从小到大
            recall(board, 0, 0);
            return;
        }

        public boolean recall(char[][] board, int rowstart, int colstart) {
            //如果该位置不为空
            if (board[rowstart][colstart] != '.') {
                if (colstart == 8 && rowstart == 8) {
                    return true;
                } else if (colstart == 8 && rowstart < 8) {
                    return recall(board, rowstart + 1, 0);
                } else {
                    return recall(board, rowstart, colstart + 1);
                }
            } else {
                //如果该位置为空
                for (char i = '1'; i <= '9'; i++) {
                    if (check(rowstart, colstart, i)) {
                        row[rowstart].put(i, 1);
                        col[colstart].put(i, 1);
                        chunk[(rowstart / 3) * 3 + colstart / 3].put(i, 1);
                        board[rowstart][colstart] = i;
                        //如果这个数可以，那么就进入
                        if (colstart == 8 && rowstart == 8) {
                            return true;
                        } else if (colstart == 8 && rowstart < 8) {
                            if (recall(board, rowstart + 1, 0)) return true;
                                //如果不匹配，那就continue
                            else {
                                board[rowstart][colstart] = '.';
                                row[rowstart].remove(i);
                                col[colstart].remove(i);
                                chunk[(rowstart / 3) * 3 + colstart / 3].remove(i);
                            }
                        } else {
                            if (recall(board, rowstart, colstart + 1)) return true;
                            else {
                                board[rowstart][colstart] = '.';
                                row[rowstart].remove(i);
                                col[colstart].remove(i);
                                chunk[(rowstart / 3) * 3 + colstart / 3].remove(i);
                            }
                        }
                    }
                }
            }
            return false;
        }

        public void initHash(char[][] board) {
            for (int i = 0; i < 9; i++) {
                row[i] = new HashMap<>( );
                col[i] = new HashMap<>( );
                chunk[i] = new HashMap<>( );
            }
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') continue;
                    else if (board[i][j] <= '9' && board[i][j] >= 1) {
                        //位置中有数字，则添加
                        row[i].put(board[i][j], 1);
                        col[j].put(board[i][j], 1);
                        chunk[(i / 3) * 3 + j / 3].put(board[i][j], 1);
                    }
                }

            }
        }

        public boolean check(int i, int j, char target) {
            /**
             * board 是数组
             */
            if (col[j].get(target) != null) return false;
            if (row[i].get(target) != null) return false;
            if (chunk[(i / 3) * 3 + j / 3].get(target) != null) return false;

            return true;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution( );
        char[][] board = new char[][]{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

        solution.solveSudoku(board);
//        solution.initHash(board);
//        HashMap<Integer,Integer> hashMap = new HashMap();
//        hashMap.put(1,1);
//        System.out.println(hashMap.get(2) );
    }
}
