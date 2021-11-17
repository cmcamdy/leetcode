from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # 只需判断数字是否有效，也就是说判断重复即可
        tmp = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
        tool_row = [[0 for j in range(9)] for i in range(9)]
        tool_col = [[0 for j in range(9)] for i in range(9)]
        tool_box = [[0 for j in range(9)] for i in range(9)]
        for row in range(9):
            for col in range(9):
                if board[row][col] in tmp:
                    if tool_row[row][int(board[row][col]) - 1] == 0:
                        tool_row[row][int(board[row][col]) - 1] = 1
                    else:
                        return False
                    # if tool_col[int(board[row][col]) - 1][col] == 0:
                    #     tool_col[int(board[row][col]) - 1][col] == 1
                    if tool_col[col][int(board[row][col]) - 1] == 0:
                        tool_col[col][int(board[row][col]) - 1] = 1
                    else:
                        return False
                    if tool_box[3 * (row // 3) +
                                col // 3][int(board[row][col]) - 1] == 0:
                        tool_box[3 * (row // 3) +
                                 col // 3][int(board[row][col]) - 1] = 1
                    else:
                        return False

        return True


if __name__ == '__main__':
    s = Solution()
    print(s.isValidSudoku([["8", "3", ".", ".", "7", ".", ".", ".", "."],
                     ["6", ".", ".", "1", "9", "5", ".", ".", "."],
                     [".", "9", "8", ".", ".", ".", ".", "6", "."],
                     ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
                     ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
                     ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                     [".", "6", ".", ".", ".", ".", "2", "8", "."],
                     [".", ".", ".", "4", "1", "9", ".", ".", "5"],
                     [".", ".", ".", ".", "8", ".", ".", "7", "9"]]))
