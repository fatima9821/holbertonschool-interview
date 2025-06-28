#!/usr/bin/python3
import sys


def is_safe(row, col, solution):
    """Check if a queen can be placed at (row, col) without conflict."""
    for r, c in solution:
        if c == col or abs(row - r) == abs(col - c):
            return False
    return True

def solve_nqueens(n, row=0, solution=[], solutions=[]):
    """Backtracking algorithm to place queens."""
    if row == n:
        solutions.append(solution[:])
        return
    for col in range(n):
        if is_safe(row, col, solution):
            solution.append([row, col])
            solve_nqueens(n, row + 1, solution, solutions)
            solution.pop()

def main():
    """Main entry: handles args and launches solution finder."""
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

    solutions = []
    solve_nqueens(n, 0, [], solutions)

    for sol in solutions:
        print(sol)

if __name__ == "__main__":
    main()
