package cmcandy.java_language_answers;

import java.util.HashMap;

/**
 * Created by CHEN on 2020/4/9.
 */
public class _0013 {


    /**
     * 字符          数值
     I             1
     V             5
     X             10
     L             50
     C             100
     D             500
     M             1000

     */

    static class Solution {
        public int romanToInt(String s) {
            HashMap<Character,Integer> hashMap = new HashMap();
            hashMap.put('I',1);
            hashMap.put('V',5);
            hashMap.put('X',10);
            hashMap.put('L',50);
            hashMap.put('C',100);
            hashMap.put('D',500);
            hashMap.put('M',1000);
            //和
            int sum = 0;
            int temp = hashMap.get(s.charAt(0));
            int index = 1;
            //非空
            while (index<s.length()){

                if (hashMap.get(s.charAt(index))>hashMap.get(s.charAt(index-1))){
                    sum  -= temp;
                    temp = hashMap.get(s.charAt(index));
                }else if (hashMap.get(s.charAt(index))<hashMap.get(s.charAt(index-1))){
                    sum  += temp;
                    temp = hashMap.get(s.charAt(index));
                }else if (hashMap.get(s.charAt(index))==hashMap.get(s.charAt(index-1))){

                    temp += hashMap.get(s.charAt(index));
                }

                index++;
            }


            return  sum+temp;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.romanToInt("III" ) );
    }
}
