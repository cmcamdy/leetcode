package cmcandy.solutions;

import java.util.Arrays;

/**
 * Created by CHEN on 2020/4/12.
 */
public class _0016 {
    static class Solution {
        public int threeSumClosest(int[] nums, int target) {
            //排序
            Arrays.sort(nums);
            //初始化
            int left = 1;
            int right = nums.length - 1;
            int ans = Integer.MAX_VALUE;
            if (nums[0]+nums[1]+nums[2]>target){
                return  nums[0]+nums[1]+nums[2];
            }else if (nums[right]+nums[right-1]+nums[right-2]<target){
                return nums[right]+nums[right-1]+nums[right-2];
            }else {
                Label:
                for (int i = 0; i < nums.length - 2; i++) {
                    left = i+1;
                    right = nums.length-1;
                    if (nums[i]+nums[i+1]+nums[i+2]>target&&Math.abs(nums[i] + nums[i+1] + nums[i+2]-target)<Math.abs(ans-target)){
                        ans = nums[i] + nums[i+1] + nums[i+2];
                        break Label;
                    }else {
                    while (right>left){
                        if (Math.abs(nums[right] + nums[i] + nums[left]-target)<Math.abs(ans-target)){
                            ans = nums[right] + nums[i] + nums[left];
                        }
                        if (nums[right] + nums[i] + nums[left] >target ) {
                            //xyz>target==>变小
                            right--;
                        }else if (nums[right] + nums[i] + nums[left] <target ) {
                            //xyz<target==>变大
                            left++;
                        } else if (nums[right] + nums[i] + nums[left]  ==target ) {
                            return target;
                        }
                    }
                }}
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
//        System.out.println(solution.threeSumClosest(new int[]{-1, 2, 1, -4}, 1));
//        System.out.println(solution.threeSumClosest(new int[]{0,2,1,-3}, 1));
        lableB:
        for(int i=0;i<3;i++){
            lableA:
            for(int j=0;j<3;j++){
                System.out.println(j);
                if(j==1){
                    break lableB;
                }
            }
        }
        System.out.println("over!");
    }


}
