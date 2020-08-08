package cmcandy.java_language_answers;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by CHEN on 2020/8/8.
 */
public class _0119 {
    static class Solution {
        public List<Integer> getRow(int rowIndex) {

            List<Integer> last = new LinkedList<>( );
            List<Integer> now = new LinkedList<>( );

            last.add(1);
            for (int i = 1; i <= rowIndex + 1; i++) {
                now = new LinkedList<>( );
                for (int j = 0; j < i; j++) {
                    if (j == 0 || j == i - 1) {
                        now.add(1);
                    } else {
                        now.add(last.get(j - 1) + last.get(j));
                    }
                }
                last = now;
            }
            return now;

        }
    }
}
