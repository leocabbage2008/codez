# 19/27
# 91/25
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split

df = pd.read_csv("diabetes.csv")
df["diabetes"].hist()
plt.show()

x = df.drop(["diabetes"], axis=1)
y = df["diabetes"]

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)
model = GaussianNB()
model.fit(x_train, y_train)
print(" Accuracy", model.score(x_test, y_test))
