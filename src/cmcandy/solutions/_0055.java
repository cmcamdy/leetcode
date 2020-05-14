package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/14.
 */
public class _0055 {

    static class Solution {
        public boolean canJump(int[] nums) {

            int len = nums.length;
            boolean tmp = true;
            //搜索数组中有没有0
            for(int i =0;i<len-1;i++){
                if(nums[i]==0){
                    tmp =false;
                    for(int j =i-1;j>=0;j--){
                        if(nums[j]>i-j) tmp=true;
                    }
                    if (tmp==false) return false;
                }
            }
            return true;
        }
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.canJump(new int[]{3,2,1,0,4}) );
    }
}
