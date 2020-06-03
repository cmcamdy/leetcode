package cmcandy.java_language_answers;

import java.util.ArrayList;

/**
 * Created by CHEN on 2020/4/21.
 */
public class _0264 {
    static class Solution {
        public static ArrayList<Integer> uglyNum = new ArrayList<>( );

        public Solution() {
            uglyNum.add(1);
        }

        public int nthUglyNumber(int n) {
            int p2 = 0;
            int p3 = 0;
            int p5 = 0;
            int num2 = uglyNum.get(p2) * 2;
            int num3 = uglyNum.get(p2) * 3;
            int num5 = uglyNum.get(p2) * 5;
            int i = 0;
            while (uglyNum.size( ) < n) {

                if (num2 <= num3 && num2 <= num5) {
                    if (num2 > uglyNum.get(i)) {
                        uglyNum.add(num2);
                        i++;
                    }
                    p2++;
                    num2 = uglyNum.get(p2) * 2;
                } else if (num3 < num2 && num3 <= num5) {
                    if (num3 > uglyNum.get(i)) {
                        uglyNum.add(num3);
                        i++;
                    }
                    p3++;
                    num3 = uglyNum.get(p3) * 3;

                } else {
                    if (num5 > uglyNum.get(i)) {
                        uglyNum.add(num5);
                        i++;
                    }
                    p5++;
                    num5 = uglyNum.get(p5) * 5;
                }
            }
            return uglyNum.get(n-1);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.nthUglyNumber(11));
        for (Integer i : Solution.uglyNum
                ) {
            System.out.println(i);

        }
//        System.out.println( Solution.uglyNum.get(17));
    }
}
