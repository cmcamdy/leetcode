package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/10.
 * 自己写的动态规划
 */
public class _0044_3 {


    static class Solution {
        public boolean isMatch(String s, String p) {

            // base cases
            if (p.equals(s) || p.equals("*")) return true;
            if (p.isEmpty( ) || s.isEmpty( )) return false;

            int slen = s.length( );
            int plen = p.length( );
            boolean[][] dp = new boolean[slen + 1][plen + 1];

            //初始化
            dp[0][0] = true;
            if(p.charAt(0)=='*'){
                // for (int j =1;j<=slen;j++){
                //     dp[j][0] = true;
                // }
                for (int j =1;j<=plen;j++){
                    if (p.charAt(j-1)=='*')
                        dp[0][j] = true;
                    else break;
                }
            }

            for (int i = 1; i <= slen; i++) {
                for (int j = 1; j <= plen; j++) {
                    //上左两个任意一个为true都可以为true
                    if (p.charAt(j - 1) == '*'&(dp[i][j - 1] || dp[i - 1][j])) dp[i][j] = true;
                        //左上角为true即可说明可以匹配到
                    else if (dp[i - 1][j - 1] ) {
                        //如果当前匹配+上一个匹配==》当前可以匹配
                        if (s.charAt(i - 1) == p.charAt(j - 1)||p.charAt(j - 1) == '?') {
                            dp[i][j] = true;
                        }

                    }
                }
            }

            return dp[slen][plen];
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        String p = "";
        System.out.println(p.length( ));
        System.out.println(solution.isMatch("hp", "*hp"));
        System.out.println(solution.isMatch("hp", "**hp"));
        System.out.println(solution.isMatch("adceb", "*a*b"));
        System.out.println(solution.isMatch("aa", "a"));
        System.out.println(solution.isMatch("aa", "*"));
        System.out.println(solution.isMatch("", "*"));
        System.out.println(solution.isMatch("acdcb", "a*c?b"));
        System.out.println(solution.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"));
        System.out.println(solution.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
    }
}
