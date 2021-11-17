class Solution:
    def longestValidParentheses(self, s: str) -> int:
        length = len(s)
        if length == 0:
            return 0
        stack = [-1]
        res = 0
        # 这里的stack里面放的是(的下标，如果说(被取走了那放的是前一个的下标（直到-1），这个是在stack下标>=1的情况
        # 而stack[0]一定是)的下标或者-1，因此，如果stack为0的话，那就说明已经断了，需要重新开始，记录本次的)作为新起点
        for index in range(len(s)):
            if s[index] == '(':
                stack.append(index)
            else:
                if len(stack) > 0:
                    stack.pop()
                    if len(stack) == 0:
                        stack.append(index)
                    else:
                        res = max(index - stack[-1], res)
        
        return res