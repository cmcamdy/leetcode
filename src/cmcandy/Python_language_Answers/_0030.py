from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        # 利用hashmap，把words搞成map，然后进行比较就是了
        map = {}
        res = []
        for word in words:
            if word in map:
                map[word] += 1
            else:
                map[word] = 1
        tmap = map.copy()
        length = len(words)
        lenw = len(words[0])
        index = 0
        while index <= len(s) - length * lenw:
            if s[index:index +
                 lenw] in tmap and tmap[s[index:index + lenw]] > 0:
                tmp = index
                while tmp < index + length * lenw and s[
                        tmp:tmp +
                        lenw] in tmap and tmap[s[tmp:tmp + lenw]] > 0:
                    tmap[s[tmp:tmp + lenw]] -= 1
                    tmp += lenw
                if tmp >= index + length * lenw:
                    res.append(index)
            tmap = map.copy()
            index += 1
        return res


if __name__ == '__main__':
    pass
    s = Solution()
    # print(s.findSubstring("barfoothefoobarman", ["foo", "bar"]))
    print(
        s.findSubstring("wordgoodgoodgoodbestword",
                        ["word", "good", "best", "good"]))
