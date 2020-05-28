package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/4/21.
 */
public class _0067 {
    static class Solution {
        public String addBinary(String a, String b) {
            //拥有一定局限性，太长就不行了，是通不过的一个版本
            long num_a = Integer.valueOf(a);
            long num_b = Integer.valueOf(b);
            long sum = num_a+num_b;
            long res = 0;
            int temp =0;
            long muti = 1;
            while(sum>0){
                temp += sum%10;
                if(temp ==0 || temp==1){
                    res+=muti*temp;
                    temp =0;
                }else if(temp>=2){
                    temp -=2;
                    res+=muti*temp;
                    temp =1;
                }
                sum /=10;
                muti*=10;
            }
            res+=muti*temp;
            return String.valueOf(res);
        }
    }

    public static void main(String[] args) {
        System.out.println(String.valueOf(123) );
        Solution solution = new Solution();
        System.out.println(solution.addBinary("1110110101","1110111011") );
    }
}
