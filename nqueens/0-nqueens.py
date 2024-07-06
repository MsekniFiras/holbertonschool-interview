#!/usr/bin/python3
''' Python3 program to solve N Queen Problem '''
import sys

if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print('N must be a number')
    exit(1)

if N < 4:
    print('N must be at least 4')
    exit(1)

def printSolution(board):
    """ A utility function to print solution """
    queens = []
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                queens.append([i, j])
    print(queens)

def isSafe(board, row, col):
    """ Check if it's safe to place a queen at board[row][col] """
    for i in range(col):
        if board[row][i]:
            return False
    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False
        i -= 1
        j -= 1
    i, j = row, col
    while j >= 0 and i < N:
        if board[i][j]:
            return False
        i += 1
        j -= 1
    return True

def solveNQUtil(board, col):
    """ Use backtracking to solve the N Queen problem """
    if col == N:
        printSolution(board)
        return True
    res = False
    for i in range(N):
        if isSafe(board, i, col):
            board[i][col] = 1
            res = solveNQUtil(board, col + 1) or res
            board[i][col] = 0
    return res

def solveNQ():
    """ Initialize the board and call the utility function """
    board = [[0 for j in range(N)] for i in range(N)]
    if not solveNQUtil(board, 0):
        print("Solution does not exist")
        return

solveNQ()