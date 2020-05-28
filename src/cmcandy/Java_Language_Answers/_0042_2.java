package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/14.
 */
public class _0042_2 {
    static class Solution {
        public int trap(int[] height) {

            int len = height.length;
            if (len < 3) return 0;
            int sum = 0;
            //左右指针
            int left=0;
            int right = len-1;

            int lmax=height[0];
            int rmax=height[len];

            while (left<right){
                //如果右边高，则先移动左边
                if (height[left]<=height[right]){
                    if (height[left]>=lmax) lmax = height[left];
                    else sum+=lmax-height[left];
                    left++;

                }else {
                    //左边高，
                    if (height[right]>=rmax) rmax = height[right];
                    else sum+=rmax-height[right];
                    right++;
                }
            }
            return sum;
        }
    }
}
