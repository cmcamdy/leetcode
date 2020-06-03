package cmcandy.java_language_answers;

import java.util.Stack;

/**
 * Created by CHEN on 2020/5/19.
 */
public class _0071 {
    static class Solution {
        public String simplifyPath(String path) {

            Stack<String> stack = new Stack<>( );
            String str;
            int fromindex = 0;
            while (fromindex >= 0) {
                int nextIndex = path.indexOf('/', fromindex + 1);
                if (nextIndex == -1) {
                    if (path.charAt(path.length( ) - 1) != '/') {
                        str = path.substring(fromindex + 1);
                    } else break;
                } else {
                    str = path.substring(fromindex + 1, nextIndex);
                }
                fromindex = nextIndex;
                if (str.equals("..")) {
                    if (!stack.isEmpty( )) stack.pop( );
                } else if (str.equals(".") || str.equals("")) continue;
                else {
                    stack.push(str);
                }

            }
            if (stack.isEmpty( )) return "/";
            StringBuilder stringBuilder = new StringBuilder( );
            while (!stack.isEmpty( )) {
                stringBuilder.insert(0, stack.pop( ));
                stringBuilder.insert(0, '/');
            }
            return stringBuilder.toString( );
        }


    }
    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.simplifyPath("/home//foo/"));
        System.out.println(solution.simplifyPath("/../"));
        System.out.println(solution.simplifyPath("/a/./b/../../c/"));
        System.out.println(solution.simplifyPath("/a/../../b/../c//.//"));
        System.out.println(solution.simplifyPath("/a//b////c/d//././/.."));
    }
}
