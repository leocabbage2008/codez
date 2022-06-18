import numpy as np
import matplotlib.pyplot as plt

fig, (ax1, ax2) = plt.subplots(1, 2)
fig.suptitle("Horizontally stacked subplots")

P = np.array(["Electronics", "Books", "Food", "Clothing"])
PR = np.array([810, 301, 303, 135])
NUR = np.array([128, 54, 35, 55])
NR = np.array([140, 64, 132, 30])

T = PR + NUR + NR
TR = np.true_divide

PPR = np.true_divide(PR, T) * 100
PNUR = np.true_divide(NUR, T) * 100
NR = np.true_divide(NR, T) * 100

ax1.bar(P, PR, bottom=NUR + NR, color="blue", label="Positive Ratings")
ax1.bar(P, NR, bottom=NUR, color="yellow", label="Negative Ratings")
ax1.bar(P, NUR, color="red", label="Neutral Ratings")
ax1.legend(loc="upper right")

ax2.bar(P, PPR, bottom=PNUR + NR, color="blue", label="Positive")
ax2.bar(P, PNUR, bottom=NR, color="yellow", label="Negative")
ax2.bar(P, NR, color="red", label="Neutral")
ax2.legend(loc="upper right")

plt.show()
