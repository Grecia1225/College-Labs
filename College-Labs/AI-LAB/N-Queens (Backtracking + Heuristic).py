from rich.console import Console
from rich.table import Table
from rich import box

def heuristic(b, r, c):   # number of conflicts with queens in earlier rows
    return sum(b[i] == c or abs(b[i] - c) == r - i for i in range(r))

def solve(b, r, n):
    if r == n:
        return True
    for c in range(n):
        if heuristic(b, r, c) == 0:
            b[r] = c
            if solve(b, r + 1, n):
                return True
            b[r] = -1                       # backtrack
    return False

n = 4
board = [-1] * n

if solve(board, 0, n):
    t = Table(show_header=False, box=box.SQUARE, show_lines=True, padding=(1, 3))
    for _ in range(n):
        t.add_column(justify="center")
    for r in range(n):
        t.add_row(*["👑" if board[r] == c else " " for c in range(n)])
    Console().print("\n[bold]FINAL SOLUTION[/bold]\n")
    Console().print(t)
else:
    print("No solution")