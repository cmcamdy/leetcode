package cmcandy.java_language_answers;

import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * Created by CHEN on 2020/8/8.
 */
public class _0119_2 {
    static class Solution {
        public List<Integer> getRow(int rowIndex) {


            List<Integer> now = new LinkedList<>( );
            long tmp = 1;
            int row = rowIndex + 1;
            for (int i = 0; i <= rowIndex; i++) {
                if (i == 0 || i == rowIndex) {
                    now.add(1);
                } else {
                    tmp = tmp * (row - i) / i;
                    now.add((int) tmp);
                }
            }
            return now;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        for (Integer a :
                solution.getRow(13)) {
            System.out.println(a);
        }

    }
}
