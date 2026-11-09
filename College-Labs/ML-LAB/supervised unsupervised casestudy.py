# Program 9: Case study - Supervised (Random Forest) vs Unsupervised (K-Means)
# Dataset: Wine (178 samples, 13 chemical features, 3 wine classes)
import matplotlib.pyplot as plt
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.ensemble import RandomForestClassifier
from sklearn.cluster import KMeans
from sklearn.metrics import accuracy_score, classification_report, adjusted_rand_score, silhouette_score

wine = load_wine()
X = StandardScaler().fit_transform(wine.data)
y = wine.target
print("Samples:", X.shape[0], "| Features:", X.shape[1], "| Classes:", list(wine.target_names))

# ---- Supervised: uses the labels ----
Xtr, Xte, ytr, yte = train_test_split(X, y, test_size=0.25, random_state=0, stratify=y)
rf = RandomForestClassifier(n_estimators=100, random_state=0).fit(Xtr, ytr)
pred = rf.predict(Xte)
print("\n--- Supervised: Random Forest ---")
print("Accuracy:", round(accuracy_score(yte, pred) * 100, 2), "%")
print(classification_report(yte, pred, target_names=wine.target_names))

# ---- Unsupervised: ignores the labels ----
km = KMeans(n_clusters=3, n_init=10, random_state=0).fit(X)
print("--- Unsupervised: K-Means ---")
print("Silhouette score:", round(silhouette_score(X, km.labels_), 3))
print("Adjusted Rand Index vs true classes:", round(adjusted_rand_score(y, km.labels_), 3))

# ---- Visualise with PCA ----
p = PCA(n_components=2).fit_transform(X)
fig, ax = plt.subplots(1, 2, figsize=(11, 4))
ax[0].scatter(p[:, 0], p[:, 1], c=y);          ax[0].set_title("True classes")
ax[1].scatter(p[:, 0], p[:, 1], c=km.labels_); ax[1].set_title("K-Means clusters")
for a in ax:
    a.set_xlabel("PC1"); a.set_ylabel("PC2")
plt.tight_layout(); plt.show()

print("\nConclusion: supervised learning is more accurate when labels exist; "
      "unsupervised learning still recovers most of the structure without labels.")