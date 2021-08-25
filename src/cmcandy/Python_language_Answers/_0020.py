class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        map = {')': '(', '}': '{', ']': '['}

        for c in s:
            if c in [')', '}', ']']:
                ex = map[c]
                if len(stack) > 0 and ex == stack[-1]:
                    stack.pop()
                else:
                    stack.append(c)
            else:
                stack.append(c)
        return len(stack) == 0