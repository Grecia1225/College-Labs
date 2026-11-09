rules = {"A": "B", "B": "C", "C": "D"}   # state -> next state toward goal
state, goal = "A", "D"

print("Start:", state, "| Goal:", goal)
while state != goal:
    nxt = rules[state]
    print(f"Current: {state} | Action: Move from {state} to {nxt}")
    state = nxt
print("Current:", state)
print("Goal Reached!")