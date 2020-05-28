package cmcandy.Java_Language_Answers;

public class _0081 {
    static class Solution {
        public boolean search(int[] nums, int target) {
                if (nums.length==0)return  false;
                if (nums.length==1) return nums[0]==target?true:false;
                int start = 0;
                int end = nums.length-1;
                while(start<end-1&&nums[start]>=nums[end]){
                    int mid = start+(end-start)/2;
                    if(nums[mid]<nums[start]) end = mid;
                    else if(nums[mid]>nums[start]) start = mid;
                    else if(nums[mid]==nums[start]) start++;
                }
                //获得了节点
                 if (nums[start]<nums[end]){
                    if (nums[0]>target||nums[nums.length-1]<target)return false;
                    return dicsearch(nums,0, nums.length-1,target);
                }
    
    
                else if(nums[start]<target||nums[end]>target) return false;
                else if(nums[0]<=target)return dicsearch(nums,0,start,target);
                else if (nums[nums.length-1]>=target)return dicsearch(nums,end,nums.length-1,target);
                else return false;
            }
    
            public boolean dicsearch(int[] nums,int first,int last,int target){
               if(first == last-1){
                    if(nums[last]>target&&nums[first]<target)return false;
                    else if (nums[last]==target) return true;
                    else if (nums[first]==target) return true;
    
                }
                int mid  = first+(last-first)/2;
                if(nums[mid] == target) return true;
                else if (nums[mid]>target) return dicsearch(nums,first,mid,target);
                else if (nums[mid]<target)return dicsearch(nums,mid,last,target);
                return  false;
            }
        }
        public static void main(String[] args) {
            Solution solution = new Solution();
            System.out.println(solution.search(new int[]{1,1,3,1}, 3));
            System.out.println(solution.search(new int[]{1,3,1,1,1}, 3));
        }
}