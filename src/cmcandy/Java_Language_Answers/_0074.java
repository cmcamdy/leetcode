package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/20.
 */
public class _0074 {
    static class Solution {
        public boolean searchMatrix(int[][] matrix, int target) {
            int row = matrix.length;
            //数组不存在，返回false
            if (row < 1) return false;
            int col = matrix[0].length;
            if (col < 1) return false;
            //超过数组的两边，返回false
            if (matrix[0][0] > target || matrix[row - 1][col - 1] < target) return false;

            for (int i = 0; i < row; i++) {
                //如果最小大于target,
                if (matrix[i][0] > target) return false;
                    //如果最大小于target 则说明下一组中
                else if (matrix[i][col - 1] < target) continue;
                else {
                    //边界等于的情况
                    if (matrix[i][0] == target || matrix[i][col - 1] == target) return true;
                    //target在这个数组里面，用二分法,
                    int right = col - 1;
                    int left = 0;
                    int mid;
                    while (left < right - 1) {
                        mid = left + (right - left) / 2;
                        if (matrix[i][mid] == target) return true;
                        else if (matrix[i][mid] > target) right = mid;
                        else if (matrix[i][mid] < target) left = mid;
                    }
                    break;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.searchMatrix(new int[][]{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, 5));
    }
}
