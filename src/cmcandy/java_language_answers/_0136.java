package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/8/18.
 */
public class _0136 {

    static class Solution {
        //^=的底层实现就是将两个数转化成2进制，而后进行异或运算
        //&=的底层实现就是将两个数转化成2进制，而后进行与运算（对应位全1才为1）
        //&=的底层实现就是将两个数转化成2进制，而后进行或运算（对应位只要一个1才为1）
        public int singleNumber(int[] nums) {

            int ans = 0;

            for(int num: nums) {
                ans ^= num;
            }

            return ans;
        }
    }

    public static void main(String[] args) {
        int[] test = {2,1,5,2,1};
        Solution solution = new Solution();
        solution.singleNumber(test);
    }

}
