package cmcandy.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by CHEN on 2020/5/15.
 */
public class _0438 {
    static class Solution {
        public List<Integer> findAnagrams(String s, String p) {
            if(p.equals("")||p.length()>s.length()) return new LinkedList<Integer>();
            char[] st = s.toCharArray( );
            char[] pt = p.toCharArray( );
            Arrays.sort(pt);
            p=String.valueOf(pt);
            LinkedList<Character> list = new LinkedList<>();
            ArrayList<Integer> res = new ArrayList<>();
            //p长度，psum为了减少计算，某些加起来就不相等的就不必计算了
            int plen = p.length();
            int psum = 0;
            int tsum = 0;
            char[] tmp =new char[plen];
            for (int t = 0 ; t<pt.length;t++
                    ) {
                psum += pt[t];
                tsum += st[t];
                tmp[t] = st[t];
            }

            boolean jud = false;
            for (int i = 0;i<=s.length()-plen;i++){
                if (i>0){
                    tsum = tsum-st[i-1]+st[i+plen-1];
                    tmp[(i-1)%plen] = st[i+plen-1];
                }
                //只有和相等了才能进行比较
                if (tsum ==psum){
                    if (jud){
                        res.add(i);
                    }
                    else {
                        char[] t2 = tmp.clone();
                        Arrays.sort(t2);
                        if (Arrays.equals(t2,pt)) {
                            res.add(i);
                            jud = true;
                        }
                    }
                }else jud = false;
            }
            return res;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution( );
        solution.findAnagrams("cbaebabacd", "abc");
        solution.findAnagrams("abacbabc", "abc");
    }
}
