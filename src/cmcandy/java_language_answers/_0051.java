package cmcandy.java_language_answers;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by CHEN on 2020/6/4.
 */
public class _0051 {

    static class Solution {
        private char[][] res;
        private int[] coord;
        private int n ;
        LinkedList<List<String>> ans = new LinkedList<>();
        public List<List<String>> solveNQueens(int n) {

            //init
            this.n = n;
            this.res = new char[n][n];
            //用于存储Q的坐标
            this.coord = new int[n];
            for(int i = 0;i<n;i++){
                for (int j = 0;j<n;j++){
                    this.res[i][j] = '.';
                }
            }

            //回朔
            //如果成功则记录，如果失败则进入下一个
            recall(0);

            return ans;
        }
        public void recall(int row){
            //到这了说明上面都成功了，设为递归出口吧
            if (row>=this.n) {
                LinkedList<String> lis =new LinkedList<>();
                for (int i = 0;i<n;i++){
                    res[i][coord[i]] = 'Q';
                    lis.addLast(String.valueOf(res[i]));
                    res[i][coord[i]] = '.';
                }
                ans.add(lis);
                return;
            }
            //row = 行号
            loop1:for(int i = 0;i<this.n;i++){
                //判断当前是否成立
                for (int j = 0;j<row;j++){
                    //三种情况不成立，分别是竖、左斜、右斜
                    if (coord[j]==i) continue loop1;
                    if (coord[j]<i&&coord[j]-j+row==i)continue loop1;
                    if (coord[j]>i&&coord[j]+j-row==i)continue loop1;
                }
                this.coord[row] = i;
                //如果匹配成功，进入下一行
                recall(row+1);
                this.coord[row] = 0;
            }
            return;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solveNQueens(4);
    }
}
