class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        self.slen = len(s)
        self.plen = len(p)
        self.s = s
        self.p = p
        # 0 = 正常，1=‘.’
        # self.tag = 0
        pind = 0
        sind = 0
        # '.' 匹配任意单个字符
        # '*' 匹配零个或多个前面的那一个元素
        return self.isMatch_help(sind, pind)

    def isMatch_help(self, sind: int, pind: int):
        if pind == self.plen:
            return sind == self.slen
        first_match = False
        if (sind != self.slen) and (self.p[pind] == self.s[sind]
                                    or self.p[pind] == '.'):
            first_match = True
        if self.plen >= pind + 2 and self.p[pind + 1] == '*':
            # 有*的情况
            return (first_match and self.isMatch_help(
                sind=sind + 1, pind=pind)) or self.isMatch_help(sind=sind,
                                                                pind=pind + 2)
        else:
            return first_match and self.isMatch_help(sind=sind + 1,
                                                     pind=pind + 1)


if __name__ == '__main__':
    s = Solution()
    print(s.isMatch('aa', 'a*'))
    # print(s.isMatch('aab', 'c*a*b'))
    # print(s.isMatch('ab', '.*c'))
    # print(s.isMatch('ab', '.*c'))
    # print(s.isMatch('a', 'ab*'))