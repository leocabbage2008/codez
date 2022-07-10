import scipy.stats as stat
import matplotlib.pyplot as plt
import numpy as np

dosage = [2, 1.5, 3, 2.4, 5, 4.5, 3.8, 1, 2.8, 1.7]
systolic_bloodpressure = [152, 148, 131, 138, 115, 120, 124, 161, 135, 144]
gender = [0, 1, 1, 0, 0, 1, 1, 0, 1, 0]
colormap = np.array(["blue", "pink"])

slope, intercept, r, p, stderr = stat.linregress(dosage, systolic_bloodpressure)

f = lambda x: slope * x + intercept

mymodel = list(map(f, dosage))


plt.scatter(dosage, systolic_bloodpressure, c=colormap[gender])
plt.plot(dosage, mymodel)
plt.plot(3.3, f(3.3), marker="s", markersize=15, color="red")
plt.show()
