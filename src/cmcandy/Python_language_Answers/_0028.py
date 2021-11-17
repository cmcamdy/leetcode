class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        lhay = len(haystack)
        lnee = len(needle)
        if lnee == 0:
            return 0
        elif lhay < lnee:
            return -1

        # 感觉可以用动态规划？还是那个字符串匹配
        # KMP
        next = self.buildNext(needle)
        j = 0
        index = 0
        while index < lhay:
            if needle[j] == haystack[index]:
                j += 1
            else:
                # 如果没有匹配到
                while j > -1 and needle[j] != haystack[index]:
                    j = next[j]
                if j == -1:
                    j = 0
                elif needle[j] == haystack[index]:
                    j += 1
            index += 1
            if j == lnee:
                return index - lnee + 1
            
        return -1



    def buildNext(self,needle:str):
        length = len(needle)
        j = 0
        k = -1
        next = [ 0 for n in range(length)]
        next[0] = -1
        while j < length - 1 :
            if k == -1 or needle[j] == needle[k]:
                k += 1
                j += 1
                next[j] = k
            else:
                k = next[k]
        return next
    def buildNextVal(self,needle:str):
        length = len(needle)
        j = 0
        k = -1
        next = [ 0 for n in range(length)]
        next[0] = -1
        while j < length - 1 :
            if k == -1 or needle[j] == needle[k]:
                k += 1
                j += 1
                if (needle[j] != needle[k]): 
                    next[j] = k  
                else :
                    #因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
                    next[j] = next[k]; 
                
            else:
                k = next[k]
        return next


if __name__ == '__main__':
    s = Solution()
    print(s.buildNext('aabaaf'))
    pass
