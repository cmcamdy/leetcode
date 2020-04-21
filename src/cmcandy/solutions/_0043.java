package cmcandy.solutions;

/**
 * Created by CHEN on 2020/4/21.
 */
public class _0043 {
    static class Solution {
        public String multiply(String num1, String num2) {

            int len_num1 = num1.length()-1;
            int len_num2 = num2.length()-1;
            char temp = '0';
            int jud=0;
            String s = "";

            for (int i = len_num1;i>=0;i--)
            if (temp=='1') s="1"+s;
            return s;
        }

        }

    public static void main(String[] args) {
        System.out.println(0+'1');
        System.out.println(0+'2');
        System.out.println(0+'3');
        System.out.println(0+'4');
        System.out.println(0+'5');
        System.out.println(0+'6');
        System.out.println(0+'7');
        System.out.println(0+'8');
        System.out.println(0+'9');
    }
}
