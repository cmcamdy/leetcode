package cmcandy.solutions;

import java.util.ArrayList;

/**
 * Created by CHEN on 2020/5/11.
 */
public class _0038 {
    static class Solution {
        public String countAndSay(int n) {
            //递归

            if (n == 1) return "1";
            if (n > 1 && n <= 30) {
                char[] tmp = countAndSay(n - 1).toCharArray( );
                int num = 1;
                StringBuilder t = new StringBuilder();
                for (int i = 1; i < tmp.length; i++) {
                    if (tmp[i] == tmp[i - 1]) num++;
                    else if (tmp[i] != tmp[i - 1]) {
                        t.append( (char)(num + 48));
                        t.append(tmp[i-1]);
                        num = 1;
                    }
                }
                t.append((char) (num + 48));
                t.append(tmp[tmp.length-1]);
                return t.toString();
            }
            return "";
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.print("{" );
        for (int i=1;i<=30;i++){
            System.out.print(",\""+solution.countAndSay(i)+"\"");
        }
        System.out.print("}");
    }
}
