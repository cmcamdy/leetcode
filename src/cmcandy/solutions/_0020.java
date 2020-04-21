package cmcandy.solutions;

import java.util.Stack;

/**
 * Created by CHEN on 2020/4/20.
 */
public class _0020 {
    static class Solution {
        public boolean isValid(String s) {
            char[] arr = s.toCharArray( );
            Stack<Character> stack = new Stack<>( );
            char temp = ' ';
            for (int i = 0; i < arr.length; i++) {
                //栈位空的时候、或者不匹配的时候放入
                if (!stack.empty( ) && ((stack.peek( ) == '(' && arr[i] == ')') || (stack.peek( ) == '{' && arr[i] == '}') || (stack.peek( ) == '[' && arr[i] == ']'))) {
                    stack.pop( );
                } else {
                    stack.push(arr[i]);
                }
            }
            return stack.empty( );
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.isValid("([)"));
        System.out.println('(' - ')');
        System.out.println('[' - ']');
        System.out.println('{' - '}');
    }
}
