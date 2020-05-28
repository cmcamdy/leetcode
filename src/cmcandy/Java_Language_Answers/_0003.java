package cmcandy.Java_Language_Answers;

import java.util.HashMap;

/**
 * Created by CHEN on 2020/4/4.
 */
public class _0003 {
    /**
     * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
     */

    class Solution {
        public int lengthOfLongestSubstring(String s) {

            int start,best_length;
            char[] str = s.toCharArray();
            start = 0;
            best_length = 0;
            HashMap<Character,Integer> map  = new HashMap<>();
            for(int i = 0 ;i<str.length;i++){
                if(map.containsKey(str[i])&&map.get(str[i])>=start){
                    //if exists
                    if (best_length<i-start){
                        best_length = i - start;
                    }
                    start = map.get(str[i])+1;
                }
                else if (i==str.length-1){
                    if (best_length<i-start+1){
                        best_length = i - start+1;
                    }
                }
                map.put(str[i],i);
            }
            return best_length;
        }
    }
}
