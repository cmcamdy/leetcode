package cmcandy.java_language_answers;
/**
 * Created by CHEN on 2020/6/2.
 */
public class _0091 {
    static class Solution {
        public int numDecodings(String s) {
            
            //每次都是  1 、2步
            //自然想到动态规划
            char[] str = s.toCharArray();
            int[] res = new int[str.length];
            res[0] = 1;
            if(str[0]=='0') return 0;
            if(str.length==1) return 1;
            if(10*(str[0]-'0')+str[1]-'0'<=26&&10*(str[0]-'0')+str[1]-'0'>10&&(str[1]-'0')>0){
                res[1] = 2;
            }
            else{
                if(str[1]=='0'&&str[0]>='3') return 0;
                res[1] = 1;
            }
            for(int i = 2;i<res.length;i++){
                if(str[i]=='0'&&(str[i-1]=='0'||str[i-1]>='3')) return 0;
                if(10*(str[i-1]-'0')+str[i]-'0'>10&&10*(str[i-1]-'0')+str[i]-'0'<=26&&(str[i]-'0')>0&&(str[i-1]-'0')>0){
                    res[i] = res[i-1]+res[i-2];
                }else{
                    if(str[i]=='0'){
                        res[i] = res[i-2];
                    }else{
                        res[i] = res[i-1];
                    }
                }
            }
            return res[str.length-1];
        }
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.numDecodings("301"));
    }
}