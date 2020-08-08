package cmcandy.java_language_answers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by CHEN on 2020/8/8.
 */
public class _0118 {

    static class Solution {
        public List<List<Integer>> generate(int numRows) {

            // =上一行的  n-1项+n项

            if (numRows == 0) return new LinkedList<>( );
            else {
                LinkedList<List<Integer>> res = new LinkedList<>( );
                List<Integer> last = new LinkedList<>( );
                last.add(1);
                for (int i = 1; i <= numRows; i++) {
                    List<Integer> now = new LinkedList<>( );
                    for (int j = 0; j < i; j++) {
                        if (j == 0 || j == i - 1) {
                            now.add(1);
                        } else {
                            now.add(last.get(j - 1) + last.get(j));
                        }
                    }
                    res.add(now);
                    last = now;
                }
                return res;
            }
        }
    }

    public static void main(String[] args) {
        Integer[] a = new Integer[]{12, 3};
//        List b = ;
        System.out.println(a);
    }

}
