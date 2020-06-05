package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/6/6.
 */
public class _1417 {
    static class Solution {
        public String reformat(String s) {
            int length = s.length();
            char[] strs = s.toCharArray();
            char[] res = new char[length+1];

            int letter = 1;
            int nletter = 0;
            int nums = 0;
            int nnums = 0;
            for(int i = 0 ;i<length;i++){
                if(strs[i]>='a'&&strs[i]<='z'){
                    if(letter>length||(letter==length&&length%2==0)) return "";
                    res[letter] = strs[i];
                    letter +=2;
                    nletter++;
                }
                else if(strs[i]>='0'&&strs[i]<='9'){
                    if(nums>length||(nums==length&&length%2==0)) return "";
                    res[nums] = strs[i];
                    nums+=2;
                    nnums++;
                }
            }
            if(nletter>nnums){
                res[letter-3]=res[0];
                return String.valueOf(res).substring(1);
            }


            return String.valueOf(res).substring(0,length);

        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.reformat("covid2019") );
    }
}
