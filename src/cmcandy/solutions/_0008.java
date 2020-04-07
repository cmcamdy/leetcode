package cmcandy.solutions;


import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by CHEN on 2020/4/6.
 */
public class _0008 {


    static class Solution {
        public int myAtoi(String str) {
            char[] arr = str.toCharArray( );
            int len = arr.length;
            int index = 0;
            long ans = 0;
            int symbol = 0;
            boolean jud = true;
            while (index < len && arr[index] == ' ') {
                // 去掉前导空格
                index++;
            }
            while (jud && index < len) {

                if (arr[index] >= 48 && arr[index] <= 57) {
                    //if num
                    if (symbol == 0) {
                        symbol = 1;
                    }
                    ans = ans * 10 + (int) arr[index] - 48;
                } else if (arr[index] < 48 || arr[index] > 57) {
                    //if not num
                    if (ans == 0 && symbol == 0) {
                        if (arr[index] == '+') {
                            symbol = 1;
                        } else if (arr[index] == '-') {
                            symbol = -1;
                        } else {
                            jud = false;
                        }
                    } else {
                        jud = false;
                    }
                }
                if (ans > Integer.MAX_VALUE) {
                    //if >maxium
                    if (symbol == 1) {
                        ans = Integer.MAX_VALUE;

                    } else if (symbol == -1) {
                        ans = Integer.MIN_VALUE;
                        symbol = 1;
                    }
                    jud = false;
                }
                index++;
            }
            return (int) (symbol * ans);
        }

    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.myAtoi("words and 987"));
    }
}
