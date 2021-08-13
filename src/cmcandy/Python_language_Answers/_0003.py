class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        pass
        # maxlen;map
        map = {}
        mlen = 0
        now = 0
        left = 0
        # right = 0
        for index in range(len(s)):
            if map.get(s[index]) is None or map.get(s[index]) == 0:
                map[s[index]] = 1
                now = now + 1
            elif map.get(s[index]) == 1:
                mlen = max(now,mlen)
                # 就需要找到左侧相同的点
                while s[index] != s[left]:
                    map[s[left]] = 0
                    left = left + 1
                    now = now - 1 
                map[s[left]] = 1
                left = left + 1
        return max(mlen,now)