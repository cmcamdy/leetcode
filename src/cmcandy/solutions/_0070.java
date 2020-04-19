package cmcandy.solutions;

import sun.awt.AWTAccessor;

/**
 * Created by CHEN on 2020/4/20.
 */
public class _0070 {
    static class Solution {
        //        public int climbStairs(int n) {
//
//            int num = 0;
//            if (n == 0 || n == 1) {
//                return 1;
//            } else {
//                num += climbStairs(n - 1);
//                num += climbStairs(n - 2);
//            }
//            return num;
//        }
        public int climbStairs(int n) {

            if (n == 0 || n == 1) {
                return 1;
            }
            int[] lis = new int[n];
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    //第一阶=1种
                    lis[i] = 1;
                } else if (i == 1) {
                    //第二阶=2种
                    lis[i] = 2;
                } else {
                    lis[i] = lis[i - 2] + lis[i - 1];
                }
            }
            return lis[n - 1];
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.climbStairs(2));
        System.out.println(solution.climbStairs(45));
    }
}
