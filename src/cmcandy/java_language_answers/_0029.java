package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/5/6.
 */
public class _0029 {
    static class Solution {
        public int divide(int dividend, int divisor) {
            if (divisor == -1 && dividend == -2147483648) return 2147483647;
            int symbol = 1;
            long divid = dividend;
            long divis = divisor;
            if (divis < 0) {
                symbol = -symbol;
                divis = -divis;
            }
            if (divid < 0) {
                symbol = -symbol;
                divid = -divid;
            } else if (divid == 0) return 0;
            if (divis == 1) return (int) (symbol > 0 ? divid : -divid);
            if (divis == divid) return symbol > 0 ? 1 : -1;
            if (divis>divid) return 0;
            long tmp = divis;
            int ans = 1;
            while (tmp+tmp < divid) {
                tmp =tmp<< 1;
                ans =ans<< 1;
            }
            ans = find_ans(tmp, ans, divid, tmp, ans);
            if (tmp > divid) ans--;
            return symbol > 0 ? ans : -ans;
        }

        public int find_ans(long tmp, int ans, long divid, long tmp_divis, int tmp_ans) {
            if (tmp + tmp_divis < divid) {
                tmp += tmp_divis;
                ans += tmp_ans;
            } else if (tmp + tmp_divis == divid){
                return ans + tmp_ans;
            }
            if (tmp_ans == 1) {
                return ans;
            }
            return find_ans(tmp, ans, divid, tmp_divis >> 1, tmp_ans >> 1);
        }

    }


    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.divide(10, 3));
        System.out.println(solution.divide(2, 2));
        System.out.println(solution.divide(-2147483648, -1));
        System.out.println(solution.divide(-2147483648, 2));
        System.out.println(solution.divide(1004958205, -2137325331));
        System.out.println(solution.divide(-1048958272, 336470323));

    }
}
