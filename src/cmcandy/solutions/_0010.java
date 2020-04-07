package cmcandy.solutions;

/**
 * Created by CHEN on 2020/4/7.
 */
public class _0010 {
    static class Solution {
        public boolean isMatch(String s, String p) {

            if (s == null && p == null) {
                return true;
            } else if (!(s != null && p != null)) {
                return false;
            }
            char[] arr_s = s.toCharArray( );
            char[] arr_p = p.toCharArray( );

            int len_s = arr_s.length;
            int len_p = arr_p.length;
            int i = 0;
            int j = 0;
            boolean jud = true;


            while (jud && i < len_p) {
                if (arr_p[i] == '.' || arr_p[i] == arr_s[j]) {
                    i++;
                    j++;
                } else if (arr_p[i] == '*') {
                    if (arr_p[i - 1] == '.') {
                        if (i == len_p - 1) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                    while (j < len_s && arr_s[j] == arr_p[i - 1]) {
                        j++;
                    }
                    i++;
                } else if (arr_p[i] != arr_s[j]) {
                    if (j == 0) {
                        i++;
                    } else if (i < len_p - 1 && arr_p[i + 1] == '*') {
                        i += 2;
                    } else {
                        jud = false;
                    }
                }
                if (i==len_p||j==len_s){
                    jud =false;
                }
            }
            if (i == len_p && j == len_s) {
                return true;
            } else {
                return false;
            }
        }
    }

    public static void main(String[] args) {
//        "aaa"
//        "a*a"
        Solution solution = new Solution( );
        System.out.println(solution.isMatch("aa", "a*"));
    }
}
