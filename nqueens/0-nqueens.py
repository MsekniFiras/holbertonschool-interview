#!/usr/bin/python3
"""N queens classical problem."""
import sys

def extract_solution(board, n):
    """Extract solution from board."""
    solutions = []
    for x in range(n):
        for y in range(n):
            if board[x][y]:
                solutions.append([x, y])
    return solutions

def position_is_valid(chessboard, position, board_size):
    """Check if a position is valid on the chessboard."""
    for i in range(board_size):
        if chessboard[position[0]][i] or chessboard[i][position[1]]:
            return False
        if position[0] + i < board_size and position[1] - i >= 0 and chessboard[position[0] + i][position[1] - i]:
            return False
        if position[0] - i >= 0 and position[1] + i < board_size and chessboard[position[0] - i][position[1] + i]:
            return False
    return True

def solve_n_queens(chessboard, column, board_size):
    """Solve N Queens problem using backtracking."""
    if column >= board_size:
        print(extract_solution(chessboard, board_size))
        return
    for i in range(board_size):
        if position_is_valid(chessboard, (i, column), board_size):
            chessboard[i][column] = True
            solve_n_queens(chessboard, column + 1, board_size)
            chessboard[i][column] = False

def main():
    """Main function to solve N Queens problem."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print('N must be at least 4')
        sys.exit(1)
    board = [[False for _ in range(N)] for _ in range(N)]

    solve_n_queens(board, 0, N)

if __name__ == "__main__":
    main()