package cmcandy.solutions;

import javax.xml.stream.events.StartDocument;
import java.awt.*;

/**
 * Created by CHEN on 2020/5/8.
 */
public class _0033 {
    static class Solution {
        public int search(int[] nums, int target) {
            if (nums.length==0)return  -1;
            if (nums.length==1) return nums[0]==target?0:-1;
            int start = 0;
            int end = nums.length-1;
            while(start<end-1){
                int mid = start+(end-start)/2;
                if(nums[mid]<nums[start]) end = mid;
                else if(nums[mid]>=nums[start]) start = mid;
            }
            //获得了节点
            if (nums[start]<nums[end]){
                if (nums[0]>target||nums[nums.length-1]<target)return -1;
                return dicsearch(nums,0, nums.length-1,target);
            }

            else if(nums[start]<target||nums[end]>target) return -1;
            else if(nums[0]<=target)return dicsearch(nums,0,start,target);
            else if (nums[nums.length-1]>=target)return dicsearch(nums,end,nums.length-1,target);
            else return -1;
        }

        public int dicsearch(int[] nums,int first,int last,int target){
            if(first == last-1){
                if(nums[last]>target&&nums[first]<target)return -1;
                else if (nums[last]==target) return last;
                else if (nums[first]==target) return first;

            }
            int mid  = first+(last-first)/2;
            if(nums[mid] == target) return mid;
            else if (nums[mid]>target) return dicsearch(nums,first,mid,target);
            else if (nums[mid]<target)return dicsearch(nums,mid,last,target);
            return  -1;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.search(new int[]{4,5,6,7,0,1,2},0) );
        System.out.println(solution.search(new int[]{4,5,6,7,0,1,2},3) );
        System.out.println(solution.search(new int[]{1,3},1) );
        System.out.println(solution.search(new int[]{1,3,5},1) );

    }

}
