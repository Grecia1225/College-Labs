# Program 3c: Naive Bayes classifier, accuracy on test data, classify a new instance
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, confusion_matrix

iris = load_iris()
Xtr, Xte, ytr, yte = train_test_split(iris.data, iris.target, test_size=0.25, random_state=0)

nb = GaussianNB().fit(Xtr, ytr)
pred = nb.predict(Xte)
print("Predicted:", pred)
print("Accuracy of Naive Bayes:", round(accuracy_score(yte, pred) * 100, 2), "%")
cm = confusion_matrix(yte, pred)
print("Confusion Matrix:\n", cm)

plt.imshow(cm, cmap="Blues")
plt.xticks(range(3), iris.target_names); plt.yticks(range(3), iris.target_names)
for i in range(3):
    for j in range(3):
        plt.text(j, i, cm[i, j], ha="center", va="center")
plt.xlabel("Predicted"); plt.ylabel("Actual"); plt.title("Naive Bayes")
plt.show()

new = [[5.1, 3.5, 1.4, 0.2]]
print("New instance", new, "->", iris.target_names[nb.predict(new)[0]])