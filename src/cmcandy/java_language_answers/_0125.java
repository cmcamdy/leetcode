package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/8/14.
 */
public class _0125 {
    static class Solution {
        public boolean isPalindrome(String s) {
            int left = 0;
            int right = s.length( ) - 1;
            while (left < right) {
                if (!isChar(s.charAt(left))) left++;
                else if (!isChar(s.charAt(right))) right--;
                else if (s.charAt(left) == s.charAt(right) || (Math.abs(s.charAt(left) - s.charAt(right)) == 32 && s.charAt(right) > '9' && s.charAt(left) > '9')) {
                    left++;
                    right--;
                } else {
                    return false;
                }
            }
            return true;
        }

        //判断是否是字母和数字
        public boolean isChar(char a) {
            return (a >= '0' && a <= '9') || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') ? true : false;
        }
    }

    public static void main(String[] args) {
        String str = "0P";
        System.out.println('0' + 0);
        System.out.println('P' + 0);
        Solution solution = new Solution( );
        System.out.println(solution.isPalindrome(str));
    }
}
