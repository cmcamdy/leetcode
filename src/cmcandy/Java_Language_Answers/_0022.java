package cmcandy.Java_Language_Answers;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by CHEN on 2020/4/21.
 */
public class _0022 {

    static class Solution {
        List<String> res = new ArrayList<>();
        public List<String> generateParenthesis(int n) {
            dfs(n, n, "");
            return res;

        }

        private void dfs(int left, int right, String s) {

            if (left==0&&right==0){
                res.add(s);
            }
            else {
                if (left>0){
                    dfs(left-1,right,s+"(");
                }if (right>left){
                    dfs(left,right-1,s+")");
                }
            }
        }
    }
}
