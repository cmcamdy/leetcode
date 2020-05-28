package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/4/21.
 */
public class _0263 {
    static class Solution {
        public boolean isUgly(int num) {
            if (num<=0){
                return false;
            }
            boolean jud = true ;
            while(jud){
                if(num%2==0){
                    num/=2;
                }
                else if (num%3==0){
                    num/=3;
                }
                else if (num%5==0){
                    num /=5;
                }else{
                    jud = false;
                }
            }
            if(num!=1){
                return false;
            }else{
                return true;
            }
        }
    }
}
