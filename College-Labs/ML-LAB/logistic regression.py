# Program 2: Linear Regression and Logistic Regression, then classify a new instance
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats
from sklearn.datasets import load_breast_cancer
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, confusion_matrix

# ---------- Linear Regression ----------
x = [1, 2, 3, 4, 5]                      # Advertising cost
y = [1, 1, 2, 2, 4]                      # Sales
slope, intercept, r, p, std_err = stats.linregress(x, y)
model = lambda v: slope * v + intercept
print("Slope:", slope, "| Intercept:", intercept, "| r:", r)
print("Predicted sales for cost 6:", round(model(6), 2))

plt.scatter(x, y)
plt.plot(x, [model(v) for v in x], lw=3, c="orange")
plt.xlabel("Advertising Cost"); plt.ylabel("Sales"); plt.title("Linear Regression")
plt.show()

# ---------- Logistic Regression ----------
data = load_breast_cancer()
X, Y = data.data[:, :2], data.target     # mean radius, mean texture -> malignant(0)/benign(1)
Xtr, Xte, ytr, yte = train_test_split(X, Y, test_size=0.25, random_state=0)
sc = StandardScaler()
Xtr, Xte = sc.fit_transform(Xtr), sc.transform(Xte)

clf = LogisticRegression(random_state=0).fit(Xtr, ytr)
pred = clf.predict(Xte)
print("\nAccuracy:", round(accuracy_score(yte, pred), 4))
print("Confusion Matrix:\n", confusion_matrix(yte, pred))

new = sc.transform([[14.0, 20.0]])       # new instance
print("New instance [radius=14, texture=20] ->", data.target_names[clf.predict(new)[0]],
      "| probabilities:", clf.predict_proba(new).round(3))