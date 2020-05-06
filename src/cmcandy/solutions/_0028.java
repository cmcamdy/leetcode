package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/6.
 */
public class _0028 {
//
//    static class Solution {
//        public int strStr(String haystack, String needle) {
//
//            if (needle.length()==0) return 0;
//            else if (haystack.length()==0) return -1;
//            boolean jud ;
//            for(int i = 0;i<haystack.length();i++){
//                if (haystack.charAt(i)==needle.charAt(0)&&i+needle.length()<=haystack.length()){
//                    jud = true;
//                    for(int j = 1;j<needle.length();j++){
//                        if (needle.charAt(j)!=haystack.charAt(i+j)){
//                            jud = false;
//                            break;
//                        }
//                    }
//                    if (jud) return i;
//                }
//
//            }
//            return -1;
//        }
//    }
    static class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length()==0) return 0;
        else if (haystack.length()==0) return -1;
        boolean jud ;
        int index = 0;
        for(int i = 0;i<haystack.length();i++){
            if (haystack.charAt(i)==needle.charAt(0)&&i+needle.length()<=haystack.length()){
                jud = true;
                for(int j = 1;j<needle.length();j++){
                    if(index==0&&needle.charAt(0)==haystack.charAt(i+j)){
                        index = i+j-1;
                    }
                    if (needle.charAt(j)!=haystack.charAt(i+j)){
                        jud = false;
                        if(index==0) i +=j-1;
                        else if (index!=0){i = index;index = 0;}
                        break;
                    }
                }
                if (jud) return i;
            }

        }
        return -1;
    }
}


    public static void main(String[] args) {
        Solution solution  = new Solution();

        System.out.println(solution.strStr("mississippi","pi") );
        System.out.println(solution.strStr("ababbbbaaabbbaaa","bbbb") );
    }
}
