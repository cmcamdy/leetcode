package cmcandy.java_language_answers;

import java.util.Arrays;

/**
 * Created by CHEN on 2020/5/15.
 */
public class _0242 {
    static class Solution {
        public boolean isAnagram(String s, String t) {
            if(s.equals(t))return true;
            if (t.length()!=s.length()) return false;
            char[] st = s.toCharArray();
            char[] tt = t.toCharArray();
            Arrays.sort(st);
            Arrays.sort(tt);
            return String.valueOf(st).equals(String.valueOf(tt));
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isAnagram("a","b") );
    }
}
