package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/18.
 */
public class _0326 {
    static class Solution {
        public boolean isPowerOfThree(int n) {
            // if(n<=0) return false;
            // while(n>1){
            //     if (n%3!=0) return false;
            //     else n/=3;
            // }
            // return true;
            return (Math.log10(n) / Math.log10(3)) % 1 == 0;
        }
    }
}
