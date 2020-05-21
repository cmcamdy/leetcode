package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/21.
 */
import java.util.ArrayList;
import java.util.List;
import java.util.LinkedList;
import javax.sound.sampled.SourceDataLine;

public class _0077 {

    static class Solution {
        int n;
        int k;
        List<List<Integer>> output = new ArrayList<>();
        public List<List<Integer>> combine(int n, int k) {
            // 递归吧，问题降维

            this.k = k;
            this.n = n;
            
            combine_in2(1, new LinkedList<>());
            
            return output;
        }

        public void combine_in2(int start,LinkedList<Integer> curr) {
                
            if(curr.size()==k){
                output.add(new LinkedList<>(curr));
            }
            for(int i = start;i<=this.n;i++){
                curr.add(i);
                combine_in2(start+1, curr);
                curr.removeLast();
            }
        }
    }
}