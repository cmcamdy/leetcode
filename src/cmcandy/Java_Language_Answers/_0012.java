package cmcandy.Java_Language_Answers;

import java.util.HashMap;

/**
 * Created by CHEN on 2020/4/11.
 */
public class _0012 {


    static class Solution {
        public String intToRoman(int num) {
            HashMap<Integer, Character> hashMap = new HashMap( );
            hashMap.put(1, 'I');
            hashMap.put(5, 'V');
            hashMap.put(10, 'X');
            hashMap.put(50, 'L');
            hashMap.put(100, 'C');
            hashMap.put(500, 'D');
            hashMap.put(1000, 'M');
            //表示基础倍数
            int mult = 1;
            int temp = 0;
//            ArrayList<Character> str = new ArrayList<>( );
            StringBuffer str = new StringBuffer();
            while (num > 0) {
                temp = num % 10;
                if (temp == 4 || temp == 9) {
                    str.insert(0,hashMap.get((temp + 1) * mult));
                    str.insert(0,hashMap.get(mult));
                } else {
                    if (temp >= 5) {
                        temp -= 5;
                        for (int i = 0; i < temp; i++) {
                            str.insert(0,hashMap.get(mult));

                        }
                        str.insert(0,hashMap.get(5 * mult));
                    }else {
                        for (int i = 0; i < temp; i++) {
                            str.insert(0,hashMap.get(mult));
                        }
                    }
                }
                num = num / 10;
                mult *=10;
            }
            return str.toString();
        }
    }


    public static void main(String[] args) {

        Solution solution  = new Solution();
        System.out.println(solution.intToRoman(61) );
    }
}
