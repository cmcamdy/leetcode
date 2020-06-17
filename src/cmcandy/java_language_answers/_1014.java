package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/6/17.
 */
public class _1014 {
    static class Solution {
        public int maxScoreSightseeingPair(int[] A) {
            int max = 0;
            int len = A.length;
            int index = 0;
            for(int i = 1; i < len; i++){
                max = Math.max(max,A[i]+A[index]-i+index);
                if(A[i]+i-index>A[index]) index = i;
            }
            return max;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.maxScoreSightseeingPair(new int[]{8,1,5,2,6}));


    }

}