import networkx as nx
import matplotlib.pyplot as plt

def minimax(node, maximizing, alpha=-999, beta=999):
    if not isinstance(node, list):          # leaf
        return node
    best = -999 if maximizing else 999
    for child in node:
        v = minimax(child, not maximizing, alpha, beta)
        if maximizing:
            best = max(best, v); alpha = max(alpha, best)
        else:
            best = min(best, v); beta = min(beta, best)
        if beta <= alpha:                   # prune
            break
    return best

tree = [[3, 5], [2, 9]]
print("Best value for MAX =", minimax(tree, True))

g = nx.DiGraph([("MAX","MIN1"), ("MAX","MIN2"),
                ("MIN1","3"), ("MIN1","5"), ("MIN2","2"), ("MIN2","9")])
pos = {"MAX":(0,2), "MIN1":(-2,1), "MIN2":(2,1),
       "3":(-3,0), "5":(-1,0), "2":(1,0), "9":(3,0)}

plt.figure(figsize=(10, 6))
nx.draw(g, pos, with_labels=True, node_size=2500, node_color="lightblue",
        font_size=14, font_weight="bold", arrows=True)
plt.title("Minimax Game Tree with Alpha-Beta Pruning")
plt.axis("off")
plt.show()