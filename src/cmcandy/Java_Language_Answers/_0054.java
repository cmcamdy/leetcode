package cmcandy.Java_Language_Answers;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by CHEN on 2020/5/16.
 */
public class _0054 {
    static class Solution {
        public List<Integer> spiralOrder(int[][] matrix) {
            int row = matrix.length;
            if (row < 1) return new ArrayList<>( );
            int cul = matrix[0].length;
            int rowstart = 0;
            int culstart = 0;
            int rowend = row - 1;
            int culend = cul - 1;
            List<Integer> res = new ArrayList<>( );
            while (culstart < culend && rowstart < rowend) {
                //→
                for (int i = culstart; i <= culend; i++) {
                    res.add(matrix[rowstart][i]);
                }
                rowstart++;
                //↓
                for (int j = rowstart; j <= rowend; j++) {
                    res.add(matrix[j][culend]);
                }
                culend--;
                //←
                for (int i = culend; i >= culstart; i--) {
                    res.add(matrix[rowend][i]);
                }
                rowend--;
                //↑
                for (int j = rowend; j >= rowstart; j--) {
                    res.add(matrix[j][culstart]);
                }
                culstart++;
            }
            if (row * cul > res.size( ))
                if (rowstart < rowend) {
                    for (int j = rowstart; j <= rowend; j++) {
                        res.add(matrix[j][culend]);
                    }
                } else if (culstart < culend) {
                    for (int i = culstart; i <= culend; i++) {
                        res.add(matrix[rowstart][i]);
                    }
                } else if (rowstart == rowend && culstart == culend) {
                    res.add(matrix[rowstart][culstart]);
                }
            return res;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.spiralOrder(new int[][]{{1, 2}, {3, 4}}));
        System.out.println(solution.spiralOrder(new int[][]{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}));
        System.out.println(solution.spiralOrder(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));
    }
}
