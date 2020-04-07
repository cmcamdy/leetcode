package cmcandy.solutions;

/**
 * Created by CHEN on 2020/4/6.
 */
public class _0007 {
    static class Solution {
        public int reverse(int x) {


            long ans = 0;
            while (x != 0) {
                ans = ans * 10 + x % 10;
                x = x / 10;
            }
            if(ans<-Math.pow(2,31)||ans>Math.pow(2,31)-1){
                return 0;
            }
            return (int)ans;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.reverse(1534236469));
        System.out.println((1534236469>(Math.pow(2,31)-1)) );
//        System.out.println((9646324351>(Math.pow(2,31)-1)) );
        System.out.println();
        System.out.println(solution.reverse(123));
    }
}
