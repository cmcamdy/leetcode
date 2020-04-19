package cmcandy.solutions;

/**
 * Created by CHEN on 2020/4/20.
 */
public class _0069 {
    static class Solution {
        public int mySqrt(int x) {
            if (x <= 0) {
                return 0;
            }
            long ans = 1;
            long min = 1;
            long max = x;
            while (true) {
                if (ans == max || min == max - 1) {
                    return (int)ans;
                } else if (ans * ans < x) {
                    min = ans;
                    ans = (min + max) / 2;
                } else if (ans * ans > x) {
                    max = ans;
                    ans = (min + max) / 2;
                } else if (ans * ans == x) {
                    return (int)ans;
                }
            }

        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.mySqrt(2147395599));
    }
}
