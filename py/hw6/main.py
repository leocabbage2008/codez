from re import L
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import *

data = pd.read_csv("abalone.csv")

plt.scatter(data["rings"], data["whole weight"])
plt.show()

data = data.drop(columns="sex")

# x = data.drop(["rings"], axis=1).values
x = data.drop(columns="rings").values
y = data["rings"]

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.25)

KNN = KNeighborsClassifier(n_neighbors=100)
KNN.fit(x_train, y_train)
print(KNN.score(x_test, y_test))

y_pred = KNN.predict(x_test)
cm = confusion_matrix(y_test, y_pred)
sns.heatmap(cm, annot=True)
plt.show()
