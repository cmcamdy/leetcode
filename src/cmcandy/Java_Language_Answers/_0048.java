package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/15.
 */
public class _0048 {
    /**
     *  0000
     *  0000
     *  0000
     *  0000
     */
    static class Solution {
        public void rotate(int[][] matrix) {
            int len = matrix.length;
            if(len<1) return;

            int tmp = 0;
            for(int i=0;i<(len+1)/2;i++){
                for (int j=i;j<len-i-1;j++){
                    tmp = matrix[i][j];
                    matrix[i][j]=matrix[len-1-j][i];
                    matrix[len-1-j][i]=matrix[len-1-i][len-1-j];
                    matrix[len-1-i][len-1-j]=matrix[j][len-1-i];
                    matrix[j][len-1-i] = tmp;
                }
            }

        }
    }

    public static void main(String[] args) {
        Solution solution =new Solution();
        solution.rotate(new int[][]{{1,2,3},{4,5,6},{7,8,9}});
    }
}
