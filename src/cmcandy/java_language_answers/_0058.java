package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/16.
 */
public class _0058 {
    class Solution {
        public int lengthOfLastWord(String s) {
            //去掉首尾空格
            s = s.trim();
            int len = s.length();
            if(len<1) return 0;
            int word = 0;
            for(int i=len-1;i>=0;i--){
                if(s.charAt(i)!=' ')word++;
                else break;
            }
            return word;
        }
    }
}
