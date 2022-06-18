import numpy as np
import matplotlib.pyplot as plt


fig, axs = plt.subplots(3,1)

data = [88,58,53,55,41,92,86,85,94,98,56,42,96,91,74,85,78,90,76,50,43,56,81,43,61,72,54,67,73,85,93,78,68,81,72,57,59,83,75,88,96,49,70,49,88,98,71,61,77,70,83,69,96,41,63,96,87,76,59,70,49,55,94,95,43,96,42,69,79,69,79,51,78,56,89,71,55,81,99,62,60,67,89,94,67,69,40,54,61,95,68,70,90,49,65,75,47,65,44,47]

print(f"Mean:{np.mean(data)}")

print(f"Median:{np.median(data)}")

print(f"Standard Deviation:{np.std(data)}")

axs[0].hist(data)
axs[1].plot(data)
axs[2].pie(data)

plt.show();