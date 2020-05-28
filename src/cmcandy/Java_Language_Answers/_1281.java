package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/18.
 */
public class _1281 {
    static class Solution {
        public int subtractProductAndSum(int n) {
            int tmp = 0 ;
            int pro =1;
            int sum = 0;
            while(n>0){
                tmp = n%10;
                pro*=tmp;
                sum+=tmp;
                n/=10;
            }
            return pro-sum;
        }
    }
}
