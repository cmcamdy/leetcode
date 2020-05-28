package cmcandy.Java_Language_Answers;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Created by CHEN on 2020/4/20.
 */
public class _0017 {

    static class Solution {
        public static HashMap<Integer, Character[]> hashMap;

        public Solution() {
            //初始化键盘字符
            hashMap = new HashMap<>( );
            hashMap.put(2, new Character[]{'a', 'b', 'c'});
            hashMap.put(3, new Character[]{'d', 'e', 'f'});
            hashMap.put(4, new Character[]{'g', 'h', 'i'});
            hashMap.put(5, new Character[]{'j', 'k', 'l'});
            hashMap.put(6, new Character[]{'m', 'n', 'o'});
            hashMap.put(7, new Character[]{'p', 'q', 'r', 's'});
            hashMap.put(8, new Character[]{'t', 'u', 'v'});
            hashMap.put(9, new Character[]{'w', 'x', 'y', 'z'});
        }

        public List<String> letterCombinations(String digits) {

            ArrayList<Character[]> ans = new ArrayList<>( );
            List<String> ret = new ArrayList<>( );
            //获得串
            int[] arr = new int[digits.length( )];
            for (int i = 0; i < digits.length( ); i++) {
                arr[i] = Integer.parseInt(digits.substring(i, i + 1));
            }
            for (int i = 0; i < arr.length; i++) {
                ans.add(hashMap.get(arr[i]));
            }

            //得到的字符数组
            for (int i = 0; i < arr.length; i++) {
                //[[],[],[],[],[],[],[]]
                ret = getString(ans.get(i), ret);
            }
            return ret;
        }

        public List<String> getString(Character[] arr, List<String> ret) {

            ArrayList<String> arrayList = new ArrayList<>( );

            if (ret.size( ) == 0) {
                for (int i = 0; i < arr.length; i++) {
                    arrayList.add(String.valueOf(arr[i]));
                }
            } else {
                //[2,3,4]
                for (int i = 0; i < arr.length; i++) {
                    for (int j = 0;j<ret.size();j++){
                        arrayList.add(ret.get(j)+String.valueOf(arr[i]));
                    }
                }
            }
            return arrayList;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.letterCombinations("234"));

    }
}
