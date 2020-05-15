package cmcandy.solutions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * Created by CHEN on 2020/5/15.
 */
public class _0049 {
    static class Solution {
        public List<List<String>> groupAnagrams(String[] strs) {
            //String to char[]
            //sort
            //对比
            if (strs.length<1) return null;
            HashMap<String,List<String>> hashMap = new HashMap<>();
            for (String s:strs
                 ) {
                char[] ch = s.toCharArray();
                //统一排列，形成key
                Arrays.sort(ch);
                String key = String.valueOf(ch);
                //如果key存在,放入
                if (hashMap.containsKey(key)) hashMap.get(key).add(s);
                else {
                    //如果不存在，则新建列表，再放入
                    List<String> lis = new ArrayList<>();
                    lis.add(s);
                    hashMap.put(key,lis);
                }
            }
            List<List<String>> res = new ArrayList<>();
            for (List<String> tmp:hashMap.values()
                 ) {
                    res.add(tmp);
            }
            return res;
        }
    }
}
