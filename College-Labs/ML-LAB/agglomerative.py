# Program 4b: Hierarchical (agglomerative) clustering and interpretation
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.cluster import AgglomerativeClustering
from scipy.cluster.hierarchy import linkage, dendrogram

x = load_iris().data

plt.figure(figsize=(10, 5))
dendrogram(linkage(x, method="ward"))
plt.title("Dendrogram (Ward linkage)"); plt.xlabel("Samples"); plt.ylabel("Distance"); plt.show()

fig, axes = plt.subplots(1, 3, figsize=(15, 4))
for ax, k in zip(axes, [2, 3, 5]):
    lab = AgglomerativeClustering(n_clusters=k, linkage="ward").fit_predict(x)
    ax.scatter(x[:, 2], x[:, 3], c=lab, cmap="viridis")
    ax.set_title(f"Agglomerative - {k} clusters")
    ax.set_xlabel("Petal Length"); ax.set_ylabel("Petal Width")
    print(f"k={k}: cluster sizes =", [int((lab == c).sum()) for c in range(k)])
plt.tight_layout(); plt.show()