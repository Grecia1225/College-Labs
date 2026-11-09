def reflex_agent(loc, status):
    if status == "Dirty":
        return "Suck"
    return "Move Right to B" if loc == "A" else "Move Left to A"

env = {"A": "Dirty", "B": "Clean"}
loc = "A"

for step in range(1, 6):
    action = reflex_agent(loc, env[loc])
    print(f"Step {step}: Room {loc} ({env[loc]}) -> {action}")
    if action == "Suck":
        env[loc] = "Clean"
    elif action.endswith("B"):
        loc = "B"
    else:
        loc = "A"
    print("Environment:", env)