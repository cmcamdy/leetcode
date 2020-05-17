package cmcandy.solutions;

import java.net.Socket;
import java.util.Arrays;

/**
 * Created by CHEN on 2020/5/16.
 */
public class _0057 {
    static class Solution {
        public int[][] insert(int[][] intervals, int[] newInterval) {

            int row = intervals.length;
            if (row<1) return new int[][]{newInterval};
            int[][] res = new int[row+1][2];
            int ids = 0;
            if(newInterval[1]<intervals[0][0]) res[ids++] = newInterval;
            int min = 0;
            int max = 0;
            for(int i = 0;i<row;i++){
                //new的值夹在两个区间的中间则:
                if (intervals[i][1]<newInterval[0]&&i<row-1&&intervals[i+1][0]>newInterval[1]){
                    res[ids++] = intervals[i];
                    res[ids++] = newInterval;
                }
                //区间左值<new 右值，加入新数组
                else if(intervals[i][1]<newInterval[0]||intervals[i][0]>newInterval[1]) res[ids++] = intervals[i];
                else{
                    //这里是这样的情况，我们可以确定的是old的前一个值与我们无关：

                    //因此我们需要判断改位置下区间两边值的比较
                    //最小值的归属
                    if(intervals[i][0]<newInterval[0]) min = intervals[i][0];
                    else min = newInterval[0];

                    //最大值的归属
                    while(i<row){

                        if(intervals[i][0]>newInterval[1]){
                            //属于本次，但与min不接壤
                            max = newInterval[1];
                            res[ids++] = new int[]{min,max};
                            res[ids++] = intervals[i];
                            break;
                        }else if(intervals[i][1]>newInterval[1]){
                            //最大值在本个区间内，因此区间合并了
                            max = intervals[i][1];
                            res[ids++] = new int[]{min,max};
                            break;
                        }
                        i++;
                    }
                }
            }
            if(intervals[row-1][1]<=newInterval[1]){
                if(intervals[row-1][1]<newInterval[0]){
                    //最小值都比老数组最大值大
                    res[ids++] = newInterval;
                }
                else{
                    res[ids++] = new int[]{min,newInterval[1]};
                }
            }
            return Arrays.copyOf(res,ids);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.insert(new int[][]{{3,5},{12,15}},new int[]{6,6});
        solution.insert(new int[][]{{1,5}},new int[]{0,5});
        solution.insert(new int[][]{{1,3},{6,9}},new int[]{2,5});
        solution.insert(new int[][]{{1,2},{3,5},{6,7},{8,10},{12,16}},new int[]{4,8});
    }
}
