package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/4/8.
 */
public class _0011 {

    /**
     * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
     * <p>
     * 说明：你不能倾斜容器，且 n 的值至少为 2。
     * <p>
     *  
     */

    static class Solution {
        public int maxArea(int[] height) {

            int letf = 0;
            int right = height.length - 1;
            int area = 0;
            while (letf < right) {
                area = Math.max(area, (right - letf) * Math.min(height[letf], height[right]));
                if (height[letf] < height[right]) {
                    letf++;
                } else {
                    right--;
                }
            }
            return area;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.maxArea(new int[]{1,3,5,2,5}));
    }

}
