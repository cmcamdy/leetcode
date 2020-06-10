package cmcandy.java_language_answers;

import sun.security.util.Length;

import java.util.HashMap;
import java.util.Set;

/**
 * Created by CHEN on 2020/6/10.
 */
public class _0076 {
    static class Solution {
        private Set<Character> keys;
        private HashMap<Character, Integer> tMap = new HashMap<>( );
        private HashMap<Character, Integer> sMap = new HashMap<>( );

        public String minWindow(String s, String t) {

            //1.拆成字符数组
            char[] strs = s.toCharArray( );
            char[] tmps = t.toCharArray( );

            int tlen = tmps.length;
            int slen = strs.length;

            //初始化，记录t中各个字母的个数
            for (int i = 0; i < tlen; i++) {
                if (tMap.get(tmps[i]) != null) {
                    tMap.put(tmps[i], tMap.get(tmps[i]) + 1);

                } else {
                    tMap.put(tmps[i], 1);
                    //顺手给smap给初始化了
                    sMap.put(tmps[i], 0);
                }
            }
            //得到key的数组
            keys = tMap.keySet( );

            //定义左右双指针，形成滑动窗口
            int left = 0;
            int right = 0;
            int start = 0;
            int end = slen;
            //判断是否满足过
            boolean jud = false;
            //判断当前是否满足
            boolean cur = false;
            //3.二维数组中寻找最短路径
            while (right < slen) {
                //如果窗口不满足
                if (!cur) {
                    //如果字符串是关键字符串，加入map
                    if (keys.contains(strs[right])) {
                        sMap.put(strs[right], sMap.get(strs[right]) + 1);
                        //也没有满足过
                        if (!jud) {
                            jud = isContain();
                            cur = jud;
                        } else {
                            //满足过
                            cur = isContain();
                        }
                    }
                    //如果到这里满足了，左侧收缩
                    if (cur) {
                        //如果是有了更加短的选择
                        if (end - start > right - left) {
                            end = right;
                            start = left;
                        }
                        left++;
                    }
                    //如果到这里还不满足，右侧继续扩张
                    else right++;
                } else {
                    //当前窗口是满足的，说明上一次是收缩的
                    if (keys.contains(strs[left - 1])) {
                        sMap.put(strs[left - 1], sMap.get(strs[left - 1]) - 1);
                        cur = isContain();
                    }
                    if (cur) {
                        //如果是有了更加短的选择
                        if (end - start > right - left) {
                            end = right;
                            start = left;
                        }
                        left++;
                    }
                    //如果到这里还不满足，右侧继续扩张
                    else right++;
                }

            }
            return s.substring(start, end + 1);
        }

        public boolean isContain() {

            //两种情况
            //第一种是在加法阶段，即一次也没满过的那种
            //用‘ ’代替没满的情况，即全部检测
            for (char k : keys) {
                if (sMap.get(k) < tMap.get(k)) return false;
            }
            return true;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.minWindow("ADOBECODEBANC", "ABC"));
    }
}
