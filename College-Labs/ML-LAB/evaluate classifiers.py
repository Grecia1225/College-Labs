# Program 7: Evaluate classifiers using Accuracy, Precision, Recall (TPR) and FPR
import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.naive_bayes import GaussianNB
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, precision_score, recall_score, confusion_matrix

iris = load_iris()
Xtr, Xte, ytr, yte = train_test_split(iris.data, iris.target, test_size=0.25, random_state=0)
sc = StandardScaler()
Xtr, Xte = sc.fit_transform(Xtr), sc.transform(Xte)

def fpr_macro(y_true, y_pred):
    cm = confusion_matrix(y_true, y_pred)
    fp = cm.sum(axis=0) - np.diag(cm)
    tn = cm.sum() - cm.sum(axis=0) - cm.sum(axis=1) + np.diag(cm)
    return np.mean(fp / (fp + tn))

models = {"Logistic Regression": LogisticRegression(),
          "Naive Bayes": GaussianNB(),
          "Decision Tree": DecisionTreeClassifier(random_state=0),
          "KNN": KNeighborsClassifier(n_neighbors=5),
          "SVM": SVC()}

print(f"{'Classifier':<20}{'Accuracy':>10}{'Precision':>11}{'TPR/Recall':>12}{'FPR':>8}")
print("-" * 61)
for name, m in models.items():
    pred = m.fit(Xtr, ytr).predict(Xte)
    print(f"{name:<20}{accuracy_score(yte, pred):>10.3f}"
          f"{precision_score(yte, pred, average='macro'):>11.3f}"
          f"{recall_score(yte, pred, average='macro'):>12.3f}"
          f"{fpr_macro(yte, pred):>8.3f}")