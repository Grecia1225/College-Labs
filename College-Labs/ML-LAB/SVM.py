# Program 3d: Support Vector Machine classifier, classify a new instance
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, confusion_matrix

iris = load_iris()
Xtr, Xte, ytr, yte = train_test_split(iris.data, iris.target, test_size=0.25, random_state=0)
sc = StandardScaler()
Xtr, Xte = sc.fit_transform(Xtr), sc.transform(Xte)

for kernel in ["linear", "rbf", "poly"]:
    svm = SVC(kernel=kernel, random_state=0).fit(Xtr, ytr)
    print(f"Kernel {kernel:6s} accuracy:", round(svm.score(Xte, yte) * 100, 2), "%")

svm = SVC(kernel="rbf", random_state=0).fit(Xtr, ytr)
pred = svm.predict(Xte)
print("\nAccuracy:", round(accuracy_score(yte, pred) * 100, 2), "%")
cm = confusion_matrix(yte, pred)
print("Confusion Matrix:\n", cm)

plt.imshow(cm, cmap="Blues")
for i in range(3):
    for j in range(3):
        plt.text(j, i, cm[i, j], ha="center", va="center")
plt.xlabel("Predicted"); plt.ylabel("Actual"); plt.title("SVM (RBF kernel)")
plt.show()

new = sc.transform([[6.5, 3.0, 5.2, 2.0]])
print("New instance -> ", iris.target_names[svm.predict(new)[0]])