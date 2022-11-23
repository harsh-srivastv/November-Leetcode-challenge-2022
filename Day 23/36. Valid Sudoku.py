# https://leetcode.com/problems/valid-sudoku/

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = defaultdict(lambda: set())
        rows = defaultdict(lambda: set())
        grids = defaultdict(lambda: set())
        for i in range(0,9):
            for j in range(0,9):
                if  board[i][j] == '.':
                    continue
                if board[i][j] in cols[j]:
                    return False
                cols[j].add(board[i][j])
                if board[i][j] in rows[i]:
                    return False
                rows[i].add(board[i][j])
                if board[i][j] in grids[10 * (i // 3) + j // 3]:
                    return False
                grids[10 * (i // 3) + j // 3].add(board[i][j])
        return True