package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/16.
 */
public class _0832 {
    static class Solution {
        public int[][] flipAndInvertImage(int[][] A) {
            int row = A.length;
            if(row<1) return A;
            int col = A[0].length;
            int tmp = 0;
            for(int i =0;i<row;i++){
                for(int j = 0;j<(col+1)/2;j++){
                    tmp = (A[i][j]+1)%2;
                    A[i][j] = (A[i][col-1-j]+1)%2;
                    A[i][col-1-j] = tmp;
                }
            }
            return A;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        for (int[] a:solution.flipAndInvertImage(new int[][]{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}})
             ) {
            for (int b:a
                 ) {
                System.out.print(b);
            }
            System.out.println( );
        }
    }
}
