package cmcandy.java_language_answers;

import java.util.*;

/**
 * Created by CHEN on 2020/5/12.
 */
public class _0039 {
    static class Solution {
        private List<List<Integer>> ans = new ArrayList<>( );

        public List<List<Integer>> combinationSum(int[] candidates, int target) {
            //用来做减法
            List<List<Integer>> ans = new ArrayList<>( );

            int len = candidates.length;
            // 排序是为了提前终止搜索
            Arrays.sort(candidates);
            //从数组中选一个（遍历选），当前目标是否够减，是则减，进入下一层
            DFS(candidates, len, target, 0, new ArrayDeque<>( ), ans);
            return ans;
        }

        public void DFS(int[] candidates, int len, int residue, int begin, Deque<Integer> path, List<List<Integer>> res) {
            if (residue == 0) {
                // 由于 path 全局只使用一份，到叶子结点的时候需要做一个拷贝
                res.add(new ArrayList<>(path));
                return;
            }

            for (int i = begin; i < len; i++) {

                // 在数组有序的前提下，剪枝
                if (residue - candidates[i] < 0) {
                    break;
                }
                path.addLast(candidates[i]);
                DFS(candidates, len, residue - candidates[i], i, path, res);
                path.removeLast( );
            }
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        List<List<Integer>> ans = solution.combinationSum(new int[]{2, 3, 6, 7}, 7);

    }

}
