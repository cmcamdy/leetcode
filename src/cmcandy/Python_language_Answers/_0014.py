from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        minlen = min([len(s) for s in strs])
        res = ""
        for index in range(minlen):
            if min([strs[0][index] == s[index] for s in strs]) == 0:
                return res
            else:
                res += strs[0][index]
        return res


if __name__ == '__main__':
    s = Solution()
    s.longestCommonPrefix(["ab", "a"])