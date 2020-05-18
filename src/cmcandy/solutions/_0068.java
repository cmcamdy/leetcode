package cmcandy.solutions;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by CHEN on 2020/5/18.
 */
public class _0068 {
    static class Solution {
        public List<String> fullJustify(String[] words, int maxWidth) {
            int len = words.length;
            int[] lens = new int[len];
            //拿到长度
            for (int i = 0; i <= len - 1; i++) {
                lens[i] = words[i].length( );
            }
            List<String> res = new ArrayList<>( );
            int tmp = 0;
            int num = 0;
            int t_width;
            for (int i = 0; i < len; i++) {
                //如果不够，则继续加
                if (lens[i] + tmp+num-1 < maxWidth) {
                    tmp += lens[i];
                    num++;
                } else {
                    if (num>1){
                    t_width = maxWidth - tmp;
                    for (int j = i - 2; j >= i - num; j--) {
                        //[1,2,3,4] j=1 i=3
                        for (int k = 0; k < t_width / (num - i + 2 + j-1); k++) {
                            words[j] += " ";
                        }
                        words[j] += words[j + 1];
                        t_width -= t_width / (num - i + 2 + j-1);
                    }
                    res.add(words[i - num]);
                    tmp = lens[i];
                    num = 1;
                }else {
                        int tlen = words[i - num].length();
                        for (int k = 0;k<maxWidth-tlen;k++){
                            words[i - num]+=" ";
                        }
                        res.add(words[i - num]);
                        tmp = lens[i];
                        num = 1;
                    }
                }
            }

            for (int j = len - 2; j >= len - num; j--) {
                    words[j] += " "+words[j + 1];
                }
                int tlen = words[len - num].length();
                for (int k = 0;k<maxWidth-tlen;k++){
                    words[len - num]+=" ";
                }
                res.add(words[len - num]);
            return res;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        solution.fullJustify(new String[]{"This", "is", "an", "example", "of", "text", "justification."}, 16);
        solution.fullJustify(new String[]{"What","must","be","acknowledgment","shall","be"}, 16);

    }
}
