class Solution:
    def convert(self, s: str, numRows: int) -> str:
        arr = ['' for i in range(numRows)]
        row = 0
        dir = 1
        for index in range(len(s)):
            arr[row] += s[index]

            if dir == 1 and row < numRows - 1:
                row += 1
            elif dir == 1 and row == numRows - 1:
                dir = 0
                row -= 1
            elif dir == 0 and row > 0:
                row -= 1
            elif dir == 0 and row == 0:
                dir = 1
                row += 1

        return ''.join(arr)


if __name__ == '__main__':
    s = Solution()
    print(s.convert('PAYPALISHIRING', 3))
    print(int('-01'))
    print((2**31) -1)