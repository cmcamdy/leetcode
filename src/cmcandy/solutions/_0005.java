package cmcandy.solutions;

import java.util.Stack;

/**
 * Created by CHEN on 2020/4/4.
 */
public class _0005 {
    /**
     * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
     * <p>
     * 示例 1：
     * <p>
     * 输入: "babad"
     * 输出: "bab"
     * 注意: "aba" 也是一个有效答案。
     * 示例 2：
     * <p>
     * 输入: "cbbd"
     * 输出: "bb"
     */

    static class Solution {
        public String longestPalindrome(String s) {
            if (s.length()==0){
                return "";
            }
            char[] arr = s.toCharArray( );
            int longest_len = 1;
            int[] index = new int[2];
            int[] answer = new int[]{0,0};
            for (int i = 1; i < arr.length; i++) {
                if (arr[i] == arr[i - 1]) {
                    //回文开始,双数回文
                    index = jud(arr,i-1,i);
                }
                if (index[1]-index[0]+1>longest_len){
                    longest_len = index[1]-index[0]+1;
                    answer = index;
                }
                if (i>=2&&arr[i] == arr[i - 2]){
                    index = jud(arr,i-2,i);
                }
                if (index[1]-index[0]+1>longest_len){
                    longest_len = index[1]-index[0]+1;
                    answer  = index;
                }
            }
            return s.substring(answer[0],answer[1]+1);
        }

        public int[] jud(char[] arr, int start, int end) {

            //保证数组不越界
            if (start - 1 >= 0 && end + 1 <= arr.length - 1) {
                //前后扩大一格，判断是否相等
                if (arr[start - 1] == arr[end + 1]) {
                    return jud(arr, start - 1, end + 1);
                } else {
                    return new int[]{start, end};
                }
            }
            return new int[]{start, end};
        }

    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.longestPalindrome("babad"));
        System.out.println(solution.longestPalindrome("cbbd"));
        System.out.println(solution.longestPalindrome("ccc"));
        System.out.println(solution.longestPalindrome("aaaa"));
    }
}
