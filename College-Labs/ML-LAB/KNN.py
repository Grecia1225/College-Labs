# Program 3b: K-Nearest Neighbour classifier, classify a new instance
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, confusion_matrix

iris = load_iris()
Xtr, Xte, ytr, yte = train_test_split(iris.data, iris.target, test_size=0.25, random_state=0)
sc = StandardScaler()
Xtr, Xte = sc.fit_transform(Xtr), sc.transform(Xte)

# Effect of k on accuracy
ks = range(1, 16)
train_acc, test_acc = [], []
for k in ks:
    m = KNeighborsClassifier(n_neighbors=k).fit(Xtr, ytr)
    train_acc.append(m.score(Xtr, ytr)); test_acc.append(m.score(Xte, yte))
plt.plot(ks, test_acc, label="Testing accuracy")
plt.plot(ks, train_acc, label="Training accuracy")
plt.xlabel("k (neighbors)"); plt.ylabel("Accuracy"); plt.legend(); plt.show()

knn = KNeighborsClassifier(n_neighbors=5, metric="minkowski", p=2).fit(Xtr, ytr)
pred = knn.predict(Xte)
print("Accuracy:", round(accuracy_score(yte, pred) * 100, 2), "%")
print("Confusion Matrix:\n", confusion_matrix(yte, pred))

new = sc.transform([[5.9, 3.0, 5.1, 1.8]])
print("New instance -> ", iris.target_names[knn.predict(new)[0]])