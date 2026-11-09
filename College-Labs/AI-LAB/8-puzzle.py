import heapq

GOAL = (1, 2, 3, 4, 5, 6, 7, 8, 0)

def h(s):   # Manhattan distance, ignoring the blank
    return sum(abs(i // 3 - GOAL.index(t) // 3) + abs(i % 3 - GOAL.index(t) % 3)
               for i, t in enumerate(s) if t)

def neighbors(s):
    z = s.index(0)
    r, c = divmod(z, 3)
    for dr, dc in (-1, 0), (1, 0), (0, -1), (0, 1):
        nr, nc = r + dr, c + dc
        if 0 <= nr < 3 and 0 <= nc < 3:
            n, k = list(s), nr * 3 + nc
            n[z], n[k] = n[k], n[z]
            yield tuple(n)

def a_star(start):
    pq, seen = [(h(start), 0, start, [start])], {}
    while pq:
        f, g, cur, path = heapq.heappop(pq)
        if cur == GOAL:
            return path
        if cur in seen and seen[cur] <= g:
            continue
        seen[cur] = g
        for n in neighbors(cur):
            heapq.heappush(pq, (g + 1 + h(n), g + 1, n, path + [n]))
    return None

start = (1, 2, 3,
         5, 6, 0,
         4, 7, 8)
sol = a_star(start)

if sol:
    print("Solution found! Moves:", len(sol) - 1, "\n")
    for i, s in enumerate(sol):
        print("Step", i)
        for r in range(0, 9, 3):
            print(*s[r:r + 3])
        print()
else:
    print("No solution exists.")