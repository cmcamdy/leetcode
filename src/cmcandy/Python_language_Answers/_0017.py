from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        self.map = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        self.length = len(digits)
        self.digits = digits
        return self.letterComb('', 0)

    def letterComb(self, s, index):

        if index == self.length:
            return [s]

        else:
            res = []
            tmps = self.map[self.digits[index]]
            for c in tmps:
                res += self.letterComb(s + c, index + 1)
            return res


if __name__ == '__main__':
    s = Solution()
    s.letterCombinations('23')