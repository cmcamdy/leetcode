package cmcandy.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by CHEN on 2020/5/16.
 */
public class _1200 {
    static class Solution {
        public List<List<Integer>> minimumAbsDifference(int[] arr) {
            if (arr.length < 2) return new ArrayList<>( );
            Arrays.sort(arr);
            List<List<Integer>> res = new ArrayList<>( );

            int min = Integer.MAX_VALUE;
            int tmp = 0;
            for (int i = 0; i < arr.length - 1; i++) {
                tmp = arr[i + 1] - arr[i];
                if (min >= tmp) {
                    if (min > tmp) {
                        min = tmp;
                        res.clear( );
                    }
                    res.add(Arrays.asList(arr[i],arr[i+1]));
                }
            }
            return res;
        }
    }
    }
