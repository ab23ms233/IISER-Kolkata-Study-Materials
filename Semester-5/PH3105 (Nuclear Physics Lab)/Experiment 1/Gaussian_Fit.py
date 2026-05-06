import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm

data = np.loadtxt('Counts.csv')
mean = np.mean(data)
std = np.std(data, ddof=1)

print(f"Mean: {mean:0.2f}")
print()
print(f"Experimental SD: {std:0.2f}")
print(f"Theoretical SD: {mean**0.5:0.2f}")

data_max = np.max(data)
data_min = np.min(data)
bins = np.arange(data_min, data_max, 4)

plt.hist(data, bins=bins, density=False, edgecolor="black", label="Experimental Data")
plt.xlabel("Counts")
plt.ylabel("Frequency")
plt.title("Histogram of Counts")

x = np.linspace(data_min, data_max, 500)
p = norm.pdf(x, mean, std)
p_scaled = p * len(data) * (bins[1] - bins[0])
plt.plot(x, p_scaled, 'r-', label="Gaussian Fit")

plt.legend()
plt.show()