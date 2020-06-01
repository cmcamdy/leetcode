public class _0088 {
    static class Solution {
        public void merge(int[] nums1, int m, int[] nums2, int n) {
    
            if(n==0) return;
            if(m==0) {for(int t = 0;t<nums2.length;t++)nums1[t] =nums2[t]; return;}
            int i = 0;int j = 0;int k = 0;
            int[] res = new int[n+m];
            while(i<m||j<n){
                if(i<m&&j<n){
                    //如果i小
                    if(nums1[i]<=nums2[j]) res[k++]=nums1[i++];
                    //如果j小
                    else if(nums2[j]<nums1[i]) res[k++] = nums2[j++];
                }else if(i==m){
                    for(int t = j;t<n;t++){
                        res[k++] = nums2[j++];
                    }    
                }else if(j==n){
                    for(int t = i;t<m;t++){
                        res[k++] = nums1[i++];
                    }
                }
            }
            for(int t =0;t<nums1.length;t++){
                nums1[t] = res[t];
            }   
        }
    }
}