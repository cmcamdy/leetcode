package cmcandy.solutions;

import javax.xml.stream.events.StartDocument;

/**
 * Created by CHEN on 2020/5/9.
 * 递归、超时
 */
public class _0044 {
    static class Solution {
        public boolean isMatch(String s, String p) {
            //动态规划
            //构造函数，传参为s 、s_index 、p 、p_index,利用递归吧
            return  recu_isMatch(s,p,0,0);
        }

        public boolean recu_isMatch(String s,String p ,int s_index,int p_index){


            if (p_index==p.length()&&s_index==s.length())return true;
            else if ((p_index==p.length()&&s_index<s.length())) return false;
            else if (s.length()==s_index){
                for (int i = p_index;i<p.length();i++){
                    if (p.charAt(i)!='*') return false;
                }
                return true;
            }
            //一个字母匹配成功,?也可以匹配
            if (s.charAt(s_index)==p.charAt(p_index)||p.charAt(p_index)=='?'){
                return recu_isMatch(s,p,s_index+1,p_index+1);
            }else if (p.charAt(p_index)=='*'){
                while (p_index<p.length()-1&&p.charAt(p_index+1)=='*'){
                    p_index++;
                }
                int tmp = p_index;
                while (tmp<p.length()-1&&p.charAt(tmp+1)!='*'&&p.charAt(tmp+1)!='?'){
                    tmp++;
                }
                while (s_index<s.length()){
                    if (tmp>p_index){
                        s_index = s.indexOf(p.substring(p_index+1,tmp+1),s_index);

                    }else if(tmp==p_index){
                        if (tmp<p.length()-1&&p.charAt(tmp+1)=='?') {
                            if (recu_isMatch(s,p,s_index+1,tmp+1)) return true;
                        }else return true;
                    }
                    if (s_index==-1) return false;
                    //如果有一种可以成功，就直接可以成功
                    if (recu_isMatch(s,p,s_index+tmp-p_index,tmp+1)) return true;
                    s_index++;
                }
            }else if (s.charAt(s_index)!=p.charAt(p_index)){
                //匹配失败
                return false;
            }
            return false;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        String p = "";
        System.out.println(p.length());
        System.out.println(solution.isMatch("aa","a") );
        System.out.println(solution.isMatch("aa","*") );
        System.out.println(solution.isMatch("","*") );
        System.out.println(solution.isMatch("acdcb","a*c?b") );
        System.out.println(solution.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba","a*******b"));
//        System.out.println(solution.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb","**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));

    }
}
