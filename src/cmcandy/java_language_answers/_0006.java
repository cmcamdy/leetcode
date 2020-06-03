package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/4/4.
 */
public class _0006 {
    /**
     * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
     * <p>
     * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
     * <p>
     * L   C   I   R
     * E T O E S I I G
     * E   D   H   N
     * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
     * <p>
     * 请你实现这个将字符串进行指定行数变换的函数：
     * <p>
     * string convert(string s, int numRows);
     * 示例 1:
     * <p>
     * 输入: s = "LEETCODEISHIRING", numRows = 3
     * 输出: "LCIRETOESIIGEDHN"
     * 示例 2:
     * <p>
     * 输入: s = "LEETCODEISHIRING", numRows = 4
     * 输出: "LDREOEIIECIHNTSG"
     * 解释:
     * <p>
     * L     D     R
     * E   O E   I I
     * E C   I H   N
     * T     S     G
     */


    static class Solution {
        public String convert(String s, int numRows) {
            char[] arr = s.toCharArray( );
            char[] ans = new char[s.length( )];
            int ans_index = 0;
            int index = 0;
            int distance = numRows * 2 - 2;
            if (s.length()<=numRows||numRows==1){
                return s;
            }
            for (int i = 0; i < numRows; i++) {
                //这个是第一行和最后一行的规则
                if ((i == 0 || i == numRows - 1)) {
                    while (index * distance + i < s.length( )) {
                        ans[ans_index] = arr[index * distance + i];
                        ans_index++;
                        index++;
                    }
                } else if (i > 0 && i < numRows - 1) {
                    //俩货的距离，有两种情况
                    int dis1 = 2 * (numRows - i - 1);
                    while ((index * distance + i < s.length( ))){
                        ans[ans_index] = arr[index * distance + i];
                        ans_index++;
                        if (index * distance + i + dis1 < s.length( )) {
                            ans[ans_index] = arr[index * distance + i + dis1];
                            ans_index++;
                        }
                        index++;
                    }
                }
                index = 0;
            }
            return String.valueOf(ans);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.convert("AB", 1));
    }
}
