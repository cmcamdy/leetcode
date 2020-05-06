package cmcandy.solutions;

import javax.xml.bind.util.JAXBSource;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.HashMap;
import java.util.List;

/**
 * Created by CHEN on 2020/5/6.
 */
public class _0030 {

    class Solution {
        public List<Integer> findSubstring(String s, String[] words) {
            List<Integer> rs = new ArrayList<>();
            if (words == null || words.length == 0) {
                return rs;
            }
            int wLen = words[0].length();
            int wTotalLen = words[0].length() * words.length;
            int sLen = s.length();
            int[] flagArray = new int[wLen];
            for (int i = 0; i < wLen; i++) {
                int flag = 0;
                for (String word : words) {
                    flag += word.charAt(i);
                }
                flagArray[i] = flag;
            }

            BitSet bs = new BitSet(words.length);
            for (int i = 0; i <= sLen - wTotalLen; i++) {
                int j = 0;
                for (; j < wLen; j++) {
                    int sumFlag = 0;
                    for (int k = 0; k < words.length; k++) {
                        sumFlag += s.charAt(i + k * wLen + j);
                    }
                    if (sumFlag != flagArray[j]) {
                        break;
                    }
                }
                if (j == wLen) {
                    // 可能匹配
                    bs.clear();
                    for (int k = 0; k < words.length; k++) {
                        String w = s.substring(i + k * wLen, i + (k + 1) * wLen);
                        int n = 0;
                        for (; n < words.length; n++) {
                            if (!bs.get(n) && words[n].equals(w)) {
                                bs.set(n);
                                break;
                            }
                        }
                        if (n == words.length) {
                            break;
                        }
                    }
                    if (bs.cardinality() == words.length) {
                        rs.add(i);
                    }

                }
            }

            return rs;
        }
    }

}
