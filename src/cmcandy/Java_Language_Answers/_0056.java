package cmcandy.Java_Language_Answers;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by CHEN on 2020/5/16.
 */
public class _0056 {

    static class Solution {
        public int[][] merge(int[][] intervals) {
            Arrays.sort(intervals, (v1, v2) -> v1[0] - v2[0]);
            int row = intervals.length;
            if (row < 1) return new int[0][0];
            int min = intervals[0][0];
            int max = intervals[0][1];
            ArrayList<int[]> res = new ArrayList<>( );
            for (int i = 1; i < row; i++) {
                if (max >= intervals[i][0]) {

                    if (min>intervals[i][0]) min = intervals[i][0];
                    if (max<intervals[i][1]) max = intervals[i][1];
                } else {
                    //如果接不上，那就存一个
                    res.add(new int[]{min, max});
                    min = intervals[i][0];
                    max = intervals[i][1];
                }
            }
            res.add(new int[]{min, max});
            int[][] ans = new int[res.size()][2];
            for(int i = 0;i<res.size();i++){
                ans[i] = res.get(i);
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        int[][] a = new int[][]{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        Solution solution = new Solution( );
        for (int[] b : solution.merge(a)
                ) {
            for (int c : b
                    ) {
                System.out.print(c);
            }
            System.out.println( );
        }

    }


}
