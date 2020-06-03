package cmcandy.java_language_answers;

import java.util.Stack;

/**
 * Created by CHEN on 2020/5/7.
 */
public class _0032 {
    static class Solution {
        public int longestValidParentheses(String s) {
            if(s == null || s.length() < 2) return 0 ;
            int ans = 0;
            Stack<Integer> stack = new Stack<>( );
            //为了避免第一次遇到）且stack为0的情况，所以需要插入一个值，-1是因为弥补数组从0开始的特点
            stack.push(-1);
            for (int i = 0; i < s.length( ); i++) {
                if (s.charAt(i) == '(') stack.push(i);
                else if (s.charAt(i) == ')') {
                    if (!stack.isEmpty( )) {
                        stack.pop( );
                        //放入最近一次开始的值
                        if (stack.isEmpty()) stack.push(i);
                        //寻找最大值，刚开始太过注重stack括号匹配的问题，括号的匹配由if控制即可
                        //在）中判断最大值是因为最大值只可能出现在由新的匹配出现的情况，即新的）
                        else ans = Math.max(i-stack.peek(),ans);
                    }
                }
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
        System.out.println(solution.longestValidParentheses("(()"));
        System.out.println(solution.longestValidParentheses(")()())"));
        System.out.println(solution.longestValidParentheses("()(()"));
        System.out.println(solution.longestValidParentheses("))))())()()(()"));
        System.out.println(solution.longestValidParentheses("())(((())"));
        System.out.println(solution.longestValidParentheses(")))()(()))())(())()())(()((())))())))))(())))(()()))(())())())))(()))()))((((()())))))()()))(()((())((())())()()()()((()((((())))(()))(()()()))))(()((((()))(((((()))())()))((("));


//        /**
//         * 结论：peek返回栈顶元素，不弹出，pop弹出
//         *      如果栈为空则会报错
//         */
//        Stack<Character> stack = new Stack<>( );
//        stack.push('s');
//        System.out.println(stack.peek( ));
//        System.out.println(stack.pop( ));
////        System.out.println(stack.peek());
////        System.out.println(stack.pop());
//        System.out.println(stack.isEmpty( ));

    }
}
