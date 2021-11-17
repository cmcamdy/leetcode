from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        self.generator('', n, n)
        return self.res
        pass

    def generator(self, s: str, left: int, right: int):
        '''
            left代表当前有多少个(
            right代表当前有多少个)
        '''
        if left == 0 and right == 0:
            self.res.append(s)
        elif left < right:
            self.generator(s + ')', left, right - 1)
            if left >= 1:
                self.generator(s + '(', left - 1, right)
        else:
            self.generator(s + '(', left - 1, right)


if __name__ == '__main__':
    s = Solution()
    print(s.generateParenthesis(3))