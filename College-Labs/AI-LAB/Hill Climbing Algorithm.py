graph = {'A':['B','C'], 'B':['D','E'], 'C':['F'], 'D':['G'], 'E':['G'], 'F':['G'], 'G':[]}
heuristic = {'A':10, 'B':7, 'C':8, 'D':3, 'E':5, 'F':6, 'G':0}

def hill_climbing(start, goal):
    current, path = start, [start]
    print("Starting Hill Climbing...\n" + "-" * 32)

    while current != goal:
        print("Current Node:", current)
        print("Current Heuristic:", heuristic[current])
        neighbors = graph[current]

        if not neighbors:
            print("No more neighbors available.\nGoal cannot be reached.")
            return path

        print("Neighbors:")
        for n in neighbors:
            print("  ", n, "-> Heuristic =", heuristic[n])

        best = min(neighbors, key=heuristic.get)
        print("Best Neighbor:", best)
        print("Best Heuristic:", heuristic[best])

        if heuristic[best] >= heuristic[current]:
            print("\nNo better neighbor found.")
            print("Hill Climbing is stuck at:", current)
            return path

        current = best
        path.append(current)
        print("Moving to:", current)
        print("-" * 32)

    print("\nGoal reached!")
    print("Goal Node:", goal)
    print("Path:", " -> ".join(path))
    return path

hill_climbing('A', 'G')