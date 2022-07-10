import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn import metrics
import seaborn as sn
import matplotlib.pyplot as plt
import numpy as np

customers = {
    "CreditScore": [
        690,
        710,
        680,
        730,
        690,
        720,
        740,
        690,
        610,
        690,
        710,
        680,
        770,
        610,
        580,
        650,
        540,
        590,
        620,
        600,
        550,
        550,
        570,
        670,
        660,
        580,
        650,
        660,
        640,
        620,
        660,
        660,
        680,
        650,
        670,
        580,
        590,
        690,
        780,
        750,
    ],
    "AnnualIncome": [
        33000,
        47000,
        39000,
        87000,
        23000,
        33000,
        33000,
        17000,
        27000,
        37000,
        37000,
        33000,
        33000,
        30000,
        27000,
        37000,
        27000,
        23000,
        33000,
        20000,
        23000,
        27000,
        30000,
        33000,
        37000,
        23000,
        37000,
        33000,
        30000,
        27000,
        40000,
        33000,
        33000,
        23000,
        27000,
        33000,
        17000,
        37000,
        40000,
        79000,
    ],
    "Approved": [
        0,
        1,
        0,
        1,
        0,
        1,
        1,
        0,
        0,
        1,
        1,
        0,
        1,
        0,
        0,
        1,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        1,
        1,
        0,
        1,
        1,
        0,
        0,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        1,
        1,
        1,
    ],
}

df = pd.DataFrame(customers, columns=["CreditScore", "AnnualIncome", "Approved"])

X = df[["CreditScore", "AnnualIncome"]]
y = df["Approved"]

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.25, random_state=0
)

logistic_regression = LogisticRegression()
logistic_regression.fit(X_train, y_train)
y_pred = logistic_regression.predict(X_test)

confusion_matrix = pd.crosstab(
    y_test, y_pred, rownames=["Actual"], colnames=["Predicted"]
)

print("Accuracy:", metrics.accuracy_score(y_test, y_pred))

new_canidates = {
    "CreditScore": [620, 570, 710],
    "AnnualIncome": [56000, 35000, 45000],
}

df2 = pd.DataFrame(new_canidates, columns=["CreditScore", "AnnualIncome"])
print(df2)

pred = logistic_regression.predict(df2)

print(pred)
