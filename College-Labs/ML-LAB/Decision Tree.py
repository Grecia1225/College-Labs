# Program 3a: Decision Tree classifier (Gini and Entropy), classify a new instance
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

iris = load_iris()
Xtr, Xte, ytr, yte = train_test_split(iris.data, iris.target, test_size=0.25, random_state=0)

for crit in ["gini", "entropy"]:
    dt = DecisionTreeClassifier(criterion=crit, max_depth=3, min_samples_leaf=5, random_state=100)
    dt.fit(Xtr, ytr)
    pred = dt.predict(Xte)
    print(f"\n=== Criterion: {crit} ===")
    print("Accuracy:", round(accuracy_score(yte, pred) * 100, 2), "%")
    print("Confusion Matrix:\n", confusion_matrix(yte, pred))
    print(classification_report(yte, pred, target_names=iris.target_names))

plot_tree(dt, feature_names=iris.feature_names, class_names=iris.target_names, filled=True)
plt.show()

new = [[5.9, 3.0, 5.1, 1.8]]
print("New instance", new, "->", iris.target_names[dt.predict(new)[0]])