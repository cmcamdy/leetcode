package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/18.
 */
public class _0342 {
    static class Solution {
        public boolean isPowerOfFour(int num) {
            return Math.log10(num) / Math.log10(4) % 1 == 0;
        }
    }
}
