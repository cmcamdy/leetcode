package cmcandy.solutions;

import java.util.ArrayList;

/**
 * Created by CHEN on 2020/4/21.
 */
public class _0067_2 {
    static class Solution {
        public String addBinary(String a, String b) {

            char[] arr1 = a.toCharArray();
            char[] arr2 = b.toCharArray();

            int len_a = arr1.length-1;
            int len_b = arr2.length-1;
            char temp = '0';
            int jud=0;
            String s = "";
            while (len_a>=0||len_b>=0){
                if (len_a<0)jud = arr2[len_b]+temp-2*48;
                else if (len_b<0)jud = arr1[len_a]+temp-2*48;
                else jud = arr1[len_a]+arr2[len_b]+temp-3*48;
                if (jud<2){
                    //0、1
                    s=String.valueOf(jud)+s;
                    temp='0';
                }else if (jud>=2){
                    //2、3
                    s=String.valueOf(jud-2)+s;
                    temp='1';
                }
                len_a--;len_b--;
            }
            if (temp=='1') s="1"+s;
            return s;
        }
    }

    public static void main(String[] args) {
        System.out.println(0+'1');
        System.out.println(0+'0');
        Solution solution = new Solution();
        System.out.println(solution.addBinary("1110110101","1110111011") );
        //11101110000
        // 1101110000
    }
}
