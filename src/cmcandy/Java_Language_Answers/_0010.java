package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/4/7.
 */
public class _0010 {
    static class Solution {
        boolean isMatch(String s, String p) {

            boolean s_empty = s.isEmpty( );
            boolean p_empty = p.isEmpty( );

            if (s_empty && p_empty) {
                return true;
            } else if ((!s_empty && p_empty)) {

                //两方有一方为空，则不匹配
                return false;
            } else if ((s_empty && !p_empty)) {
                if (p.length( ) == 1 || p.charAt(1) != '*') {
                    return false;
                } else if (p.length( ) > 1 && p.charAt(1) == '*') {
                    return isMatch(s, p.substring(2));
                }
            } else {
                //两方都不为空

                if ((p.charAt(0) == s.charAt(0) || p.charAt(0) == '.') && (p.length( ) == 1 || p.charAt(1) != '*')) {
                    //考虑没有* 的情况 字母匹配成功
                    return isMatch(s.substring(1), p.substring(1));

                } else if (p.length( ) > 1) {
                    if (p.charAt(0) != '.' && p.charAt(1) == '*') {
                        //考虑有*的情况
                        int indexs = 0;
                        while (indexs < s.length( ) && s.charAt(indexs) == p.charAt(0)) {
                            //考虑相等情况
                            boolean jud = isMatch(s.substring(indexs), p.substring(2));
                            if (jud) {
                                return true;
                            }
                            indexs++;
                        }
                        return isMatch(s.substring(indexs), p.substring(2));
                    } else if (p.charAt(0) == '.' && p.charAt(1) == '*') {
                        //考虑 '.'+'*'的情况
                        int indexs = 0;
                        while (indexs < s.length( )) {
                            //考虑相等情况
                            boolean jud = isMatch(s.substring(indexs), p.substring(2));
                            if (jud) {
                                return true;
                            }
                            indexs++;
                        }
                        return isMatch(s.substring(indexs), p.substring(2));
                    }
                }
            }
            return false;
        }
    }


    public static void main(String[] args) {
//        "aaa"
//        "a*a"
        Solution solution = new Solution( );
        System.out.println(solution.isMatch("mississippi", "mis*is*p*."));//f
//        System.out.println(solution.isMatch("aab", "c*a*b"));
        System.out.println(solution.isMatch("ab", ".*c"));//f
        System.out.println(solution.isMatch("aaa", "ab*a*c*a"));//t
        System.out.println(solution.isMatch("a", "ab*"));//t
        System.out.println(solution.isMatch("bbbbba", ".*a*a"));//t
        System.out.println(solution.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*b"));//t
        //"mississippi"
//        "mis*is*p*."
    }
}
