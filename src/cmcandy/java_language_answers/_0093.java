package cmcandy.java_language_answers;

import javax.lang.model.util.ElementScanner6;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by CHEN on 2020/8/7.
 */
public class _0093 {
    static class Solution {
        public List<String> restoreIpAddresses(String s) {
            List<String> res =getIP(s, 0, 4);
            return res==null?new  LinkedList<>( ):res;
        }

        public List<String> getIP(String s, int start, int deep) {

            //IP只有四部分
            if (deep == 1) {
                if (start < s.length( ) && Integer.valueOf(s.substring(start)) <= 255) {
                    if ((s.length( )-1>start&&s.charAt(start)!='0')|| s.length( )-1==start)
                    {
                        List<String> strs = new LinkedList<>( );
                        strs.add(s.substring(start));
                        return strs;
                    }
                    return null;
                } else return null;
            } else {
                if (s.length( ) - start > deep * 3) return null;
                else {
                    List<String> tmp;
                    List<String> res = new LinkedList<>( );
                    for (int i = start; i < start + 3; i++) {
                        if (i < s.length( )) {
                            int tm = Integer.valueOf(s.substring(start, i + 1));
                            //多位开头不能为0
                            if (tm <= 255 && ((i > start && s.charAt(start) != '0') || i == start)) {
                                tmp = getIP(s, i + 1, deep - 1);
                                if (tmp != null) {
                                    for (String t : tmp
                                            ) {
                                        //这里还需要加上自己的东西
                                        res.add(s.substring(start, i + 1) + "." + t);
                                    }
                                }
                            }
                        }
                    }
                    return res;
                }
            }
        }

    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.restoreIpAddresses("1231231231234"));
    }
}
