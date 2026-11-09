# Program 6: Build a classifier (Decision Tree) and compare it with Random Forest
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix

iris = load_iris()
Xtr, Xte, ytr, yte = train_test_split(iris.data, iris.target, test_size=0.25, random_state=0)

dt = DecisionTreeClassifier(random_state=0).fit(Xtr, ytr)
rf = RandomForestClassifier(n_estimators=100, random_state=0).fit(Xtr, ytr)

accs = {}
for name, m in [("Decision Tree", dt), ("Random Forest", rf)]:
    pred = m.predict(Xte)
    accs[name] = accuracy_score(yte, pred) * 100
    print(f"\n{name}\nTest accuracy: {accs[name]:.2f}%")
    print("Confusion Matrix:\n", confusion_matrix(yte, pred))
    print("5-fold CV accuracy: %.2f%%" % (cross_val_score(m, iris.data, iris.target, cv=5).mean() * 100))

print("\nRandom Forest feature importances:")
for f, i in zip(iris.feature_names, rf.feature_importances_):
    print(f"  {f}: {i:.3f}")

plt.bar(accs.keys(), accs.values(), color=["tab:blue", "tab:green"])
plt.ylabel("Accuracy (%)"); plt.title("Decision Tree vs Random Forest"); plt.ylim(80, 100); plt.show()