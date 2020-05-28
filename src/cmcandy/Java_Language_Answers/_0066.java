package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/19.
 */
public class _0066 {
    static class Solution {
        public int[] plusOne(int[] digits) {
            int len = digits.length;
            digits[len - 1]++;
            for (int i = len - 1; i >= 1; i--) {
                if (digits[i] == 10) {
                    digits[i] = 0;
                    digits[i - 1]++;
                } else if (digits[i] < 10) {
                    break;
                }
            }
            if (digits[0] == 10) {
                int[] res = new int[len + 1];
                res[0] = 1;
                res[1] = 0;
                for (int i = 2; i < len + 1; i++) {
                    res[i] = digits[i - 1];
                }
                return res;
            }
            return digits;
        }
    }
}
