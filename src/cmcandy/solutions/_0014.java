package cmcandy.solutions;

/**
 * Created by CHEN on 2020/4/9.
 */
public class _0014 {
    static class Solution {
        public String longestCommonPrefix(String[] strs) {

            boolean jud = true;
            String ans = "";
            int index = 0;
            int len = strs.length;
            if (len == 0) {
                return "";
            }
            int min = Integer.MAX_VALUE;
            for (int i = 0; i < len; i++) {
                if (min>strs[i].length()){
                    min = strs[i].length();
                }
            }
            while (index < strs[0].length( )) {
                for (int i = 1; i < len; i++) {
                    if (strs[i].charAt(index) != strs[i - 1].charAt(index)) {
                        jud = false;
                    }
                }
                if (!jud) {
                    break;
                }
                index++;
            }
            ans = strs[0].substring(0, index);
            return ans;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.longestCommonPrefix(new String[]{"aaa", "aaa", "aac"}));
    }
}
