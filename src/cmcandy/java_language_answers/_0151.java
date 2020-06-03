package cmcandy.java_language_answers;

import java.util.Stack;

public class _0151 {

    static class Solution {
        public int evalRPN(String[] tokens) {

            // 逆波兰表达式：栈求值
            Stack<Integer> stack = new Stack<>();
            for (String str : tokens) {
                int tmp = str.charAt(0);
                if(str.length()==1&&(tmp=='+'||tmp=='-'||tmp=='*'||tmp=='/')){
                    int a = stack.pop();
                    int b = stack.pop();
                    switch(tmp){
                        case'+':
                            stack.push(a+b);
                            break;
                        case '-':
                            stack.push(b-a);
                            break;
                        case '*':
                            stack.push(a*b);
                            break;
                        case '/':
                            stack.push(b/a);
                            break;
                    }
                }else {
                    stack.push(Integer.parseInt(str));
                }
            }
            return stack.pop();
        }
    }

    public static void main(String[] args) {
        System.out.println('0');
        String[] strs = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        Solution solution = new Solution();
        System.out.println(solution.evalRPN(strs));
    }

}