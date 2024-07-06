#!/usr/bin/python3
"""N queens classical problem."""
import sys

def print_solution(queens):
    """Print the list of queens' positions."""
    solution = []
    for i in range(len(queens)):
        solution.append([i, queens[i]])
    print(solution)

def is_safe(queens, row, col):
    """Check if a queen can be placed on board at row, col."""
    for i in range(row):
        if queens[i] == col or \
           queens[i] - i == col - row or \
           queens[i] + i == col + row:
            return False
    return True

def solve_nqueens(n, row, queens):
    """Use backtracking to find all solutions."""
    if row == n:
        print_solution(queens)
    else:
        for col in range(n):
            if is_safe(queens, row, col):
                queens[row] = col
                solve_nqueens(n, row + 1, queens)
                queens[row] = -1

def nqueens(n):
    """Main function to solve the N queens puzzle."""
    queens = [-1] * n
    solve_nqueens(n, 0, queens)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    nqueens(n)
    