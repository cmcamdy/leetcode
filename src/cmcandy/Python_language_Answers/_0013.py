class Solution:
    def romanToInt(self, s: str) -> int:

        map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        res = 0
        last = 0
        for c in s:
            if map[c] > last:
                res -= 2 * last
            res += map[c]
            last = map[c]

        return res
