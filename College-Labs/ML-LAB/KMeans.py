# Program 4a: K-Means clustering (Elbow method) and interpretation
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.cluster import KMeans

iris = load_iris()
x = iris.data

# Elbow method to find the optimum k
inertia = []
for k in range(1, 11):
    inertia.append(KMeans(n_clusters=k, init="k-means++", n_init=10, random_state=0).fit(x).inertia_)
plt.plot(range(1, 11), inertia, marker="o")
plt.title("Elbow Method"); plt.xlabel("Number of clusters"); plt.ylabel("WCSS"); plt.show()

km = KMeans(n_clusters=3, init="k-means++", max_iter=300, n_init=10, random_state=0)
labels = km.fit_predict(x)

for c, colour in zip(range(3), ["red", "blue", "green"]):
    plt.scatter(x[labels == c, 0], x[labels == c, 1], s=60, c=colour, label=f"Cluster {c}")
plt.scatter(km.cluster_centers_[:, 0], km.cluster_centers_[:, 1], s=200, c="yellow", edgecolors="k", label="Centroids")
plt.xlabel("Sepal Length"); plt.ylabel("Sepal Width"); plt.title("K-Means (k=3)"); plt.legend(); plt.show()

print("Cluster centres:\n", km.cluster_centers_.round(2))
print("Cluster sizes:", [int((labels == c).sum()) for c in range(3)])