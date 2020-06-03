package cmcandy.java_language_answers;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by CHEN on 2020/5/13.
 */
public class _0040 {
    static class Solution {
        public List<List<Integer>> combinationSum2(int[] candidates, int target) {

            List<List<Integer>> ans = new ArrayList<>( );
            int len = candidates.length;
            //排序，便于后面消除重复
            Arrays.sort(candidates);
            DFS(candidates,len, target, 0, new ArrayDeque<>( ), ans);
            return ans;

        }

        public void DFS(int[] candidates, int len,int target, int begin, ArrayDeque<Integer> path, List<List<Integer>> ans) {

            if (target==0){
                //只加入不存在的路径
                if (ans.size()==0||ans.lastIndexOf(new ArrayList<>(path))==-1) ans.add(new ArrayList<>(path));
                return;
            }

            for (int i = begin;i<len;i++){
                if (target-candidates[i]<0) break;
                //为了排除类似11两个连着的情况，减少计算量
                if (i>=1&&candidates[i]==candidates[i-1]&&path.size()==0)continue;
                path.add(candidates[i]);
                DFS(candidates,len,target-candidates[i],i+1,path,ans);
                path.removeLast();
            }

        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.combinationSum2(new int[]{10,1,2,7,6,1,5},8);
    }
}
