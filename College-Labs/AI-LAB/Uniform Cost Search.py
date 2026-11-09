import heapq
import networkx as nx
import matplotlib.pyplot as plt

graph = {
    'A': [('B',2), ('C',5)],
    'B': [('A',2), ('D',4), ('E',1)],
    'C': [('A',5), ('F',2)],
    'D': [('B',4), ('G',3)],
    'E': [('B',1), ('G',6)],
    'F': [('C',2), ('G',2)],
    'G': [('D',3), ('E',6), ('F',2)]
}

def ucs(graph, start, goal):
    pq, best = [(0, start, [start])], {}
    while pq:
        cost, node, path = heapq.heappop(pq)
        print("Expanding:", node, "| Cost:", cost, "| Path:", " -> ".join(path))
        if node in best and cost > best[node]:
            continue
        best[node] = cost
        if node == goal:
            return path, cost
        for nb, w in graph[node]:
            if nb not in best or cost + w < best[nb]:
                heapq.heappush(pq, (cost + w, nb, path + [nb]))
    return None, float('inf')

path, cost = ucs(graph, 'A', 'G')
print("\nMinimum Cost Path:", " -> ".join(path))
print("Minimum Cost:", cost)

# Visualization
G = nx.Graph()
for u in graph:
    for v, w in graph[u]:
        G.add_edge(u, v, weight=w)
path_edges = list(zip(path, path[1:]))

pos = nx.spring_layout(G, seed=42)
plt.figure(figsize=(10, 7))
nx.draw_networkx_nodes(G, pos, node_color='lightblue', node_size=1500)
nx.draw_networkx_edges(G, pos, edge_color='gray', width=2)
nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='red', width=4)
nx.draw_networkx_labels(G, pos, font_size=14, font_weight='bold')
nx.draw_networkx_edge_labels(G, pos, edge_labels=nx.get_edge_attributes(G, 'weight'))
plt.title("Uniform Cost Search - Minimum Cost Path")
plt.axis('off')
plt.show()