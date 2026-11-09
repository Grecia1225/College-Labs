# Program 5: Ensemble techniques - Bagging, Boosting (AdaBoost) and Random Forest
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.ensemble import BaggingClassifier, AdaBoostClassifier, RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix

iris = load_iris()
Xtr, Xte, ytr, yte = train_test_split(iris.data, iris.target, test_size=0.25, random_state=0)

models = {
    "Bagging (GaussianNB)": BaggingClassifier(estimator=GaussianNB(), n_estimators=100, random_state=0),
    "Boosting (AdaBoost)":  AdaBoostClassifier(n_estimators=50, learning_rate=0.2, random_state=0),
    "Random Forest":        RandomForestClassifier(n_estimators=100, random_state=0),
}

for name, m in models.items():
    m.fit(Xtr, ytr)
    pred = m.predict(Xte)
    print(f"\n=== {name} ===")
    print("Accuracy:", round(accuracy_score(yte, pred) * 100, 2), "%")
    print("Confusion Matrix:\n", confusion_matrix(yte, pred))