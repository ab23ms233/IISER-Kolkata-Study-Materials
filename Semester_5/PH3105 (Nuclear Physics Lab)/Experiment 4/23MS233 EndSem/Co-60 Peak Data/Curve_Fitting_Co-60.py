import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

def two_gauss_lin(x, A1, mu1, s1, A2, mu2, s2, p0, p1, p2):
    g1 = A1 * np.exp(-(x-mu1)**2/(2*s1**2))
    g2 = A2 * np.exp(-(x-mu2)**2/(2*s2**2))
    return g1 + g2 + p0 + p1*x + p2*x**2

data = np.loadtxt("Calibration_Co-60.txt")
x = data[:, 0]; y = data[:, 1]

p0 = [3800, 450, 10, 2900, 510, 10, 10, 1, 1]  # initial guesses
popt, pcov = curve_fit(two_gauss_lin, x, y, p0=p0)
perr = np.sqrt(np.diag(pcov))

A1, mu1, s1, A2, mu2, s2, p0_, p1_, p2_ = popt

FWHM1 = 2.35482*s1
area1 = A1*np.sqrt(2*np.pi)*s1
FWHM2 = 2.35482*s2
area2 = A2*np.sqrt(2*np.pi)*s2

print("Peak1 centroid (ch):", mu1, "+/-", perr[1])
print("Peak1 FWHM (ch):", FWHM1)
print("Peak1 area:", area1)
print()
print("Peak2 centroid (ch):", mu2, "+/-", perr[1])
print("Peak2 FWHM (ch):", FWHM2)
print("Peak2 area:", area2)

plt.figure(figsize=(8,5))
plt.scatter(x, y, s=15, color='black', label='Experimental data')
plt.plot(x, two_gauss_lin(x, *popt), 'r-', lw=2, label='2-Gaussian fit')

plt.xlabel("Channel number", fontsize=13)
plt.ylabel("Counts", fontsize=13)
plt.title("Co-60 Gamma Spectrum Fit", fontsize=15, fontweight='bold')
plt.legend(fontsize=11)
plt.grid(alpha=0.3)
plt.tight_layout()
plt.show()