package cmcandy.Java_Language_Answers;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by CHEN on 2020/5/19.
 */
public class _0073 {
    static class Solution {
        public void setZeroes(int[][] matrix) {
            int row = matrix.length;
            if (row<1) return;
            int col = matrix[0].length;
            List<Integer> rlis = new ArrayList<>();
            List<Integer> clis = new ArrayList<>();
            for(int i = 0;i<row;i++){
                for(int j =0;j<col;j++){
                    if(matrix[i][j]==0){
                        if (rlis.indexOf(i)>=0)
                            rlis.add(i);
                        if (clis.indexOf(j)>=0)
                            clis.add(j);
                    }
                }
            }
            int[] tmp = new int[col];
            for(int i:rlis){
                matrix[i] = tmp;
            }
            for(int i:clis){
                for(int j = 0;j<row;j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        solution.setZeroes(new int[][]{{0,1,2,0},{3,4,5,2},{1,3,1,5}});
        solution.setZeroes(new int[][]{{1,1,1},{1,0,1},{1,1,1}});
    }
}
