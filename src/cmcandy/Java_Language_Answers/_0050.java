package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/4/19.
 */
public class _0050 {
    static class Solution {
        public double myPow(double x, int n) {


            if (n<Integer.MIN_VALUE||n>Integer.MAX_VALUE){
                return x;
            }
//            boolean minus = false;
            if (n==0){
                return 1.0;
            }else if (n<0){
                if (n==Integer.MIN_VALUE){
                    return 1/myPow(x,-(n/2));
                }
                return 1/myPow(x,-n);
            }else if (n>0){
                if (n==1){
                    return x;
                }
                else if (n %2 ==0){
                    return myPow(x*x,n/2);
                }else if (n%2==1){
                    return x*myPow(x*x,n/2);
                }
            }
            return 0.0;
        }
    }


    public static void main(String[] args) {
        System.out.println(Integer.MIN_VALUE>=-2147483648 );
        System.out.println(Integer.MIN_VALUE==-2147483648 );
        System.out.println(Integer.MAX_VALUE );
        int n = -2147483648;
        System.out.println(-(n/2));
        Solution solution  =new Solution();
        System.out.println(solution.myPow(1.0,-2147483648));
    }
}
