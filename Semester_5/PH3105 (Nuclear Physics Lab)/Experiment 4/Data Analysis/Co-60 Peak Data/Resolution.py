import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import os
import re

# --- Gaussian + linear background ---
def gauss_linear(x, A, mu, sigma, m, c):
    return A * np.exp(-((x - mu)**2) / (2 * sigma**2)) + m*x + c

# --- FWHM and resolution ---
def fwhm(sigma):
    return 2.355 * abs(sigma)

def resolution(fwhm, mu):
    return (fwhm / abs(mu)) * 100

# --- Analyze single file ---
def analyze_resolution(filename, voltage):
    # Read file and split into 2 regions (for the 2 peaks)
    with open(filename, 'r') as f:
        content = f.read().strip()
    parts = [p for p in content.split('\n\n') if p.strip()]
    if len(parts) != 2:
        raise ValueError(f"{filename}: expected 2 data regions separated by blank line")

    # Load each part
    data1 = np.loadtxt(parts[0].splitlines())
    data2 = np.loadtxt(parts[1].splitlines())

    x1, y1 = data1[:, 0], data1[:, 1]
    x2, y2 = data2[:, 0], data2[:, 1]

    # --- Fit both peaks ---
    p0_1 = [max(y1), x1[np.argmax(y1)], 5, 0, min(y1)]
    popt1, _ = curve_fit(gauss_linear, x1, y1, p0=p0_1)
    A1, mu1, sigma1, m1, c1 = popt1

    p0_2 = [max(y2), x2[np.argmax(y2)], 5, 0, min(y2)]
    popt2, _ = curve_fit(gauss_linear, x2, y2, p0=p0_2)
    A2, mu2, sigma2, m2, c2 = popt2

    # --- Compute FWHM and resolutions ---
    deltaCN1 = fwhm(sigma1)
    deltaCN2 = fwhm(sigma2)
    r1 = resolution(deltaCN1, mu1)
    r2 = resolution(deltaCN2, mu2)

    print(f"Voltage {voltage} V:")
    print(f" Peak 1 -> μ = {mu1:.2f}, FWHM = {deltaCN1:.2f}, R = {r1:.2f}%")
    print(f" Peak 2 -> μ = {mu2:.2f}, FWHM = {deltaCN2:.2f}, R = {r2:.2f}%")

    # --- Save results ---
    outfile = "Resolution_Data.txt"
    header = "V\tΔCN1\tCN1\tr1(%)\tΔCN2\tCN2\tr2(%)\n"
    line = f"{voltage}\t{deltaCN1:.4f}\t{mu1:.4f}\t{r1:.4f}\t{deltaCN2:.4f}\t{mu2:.4f}\t{r2:.4f}\n"

    if not os.path.exists(outfile):
        with open(outfile, 'w') as f:
            f.write(header)
            f.write(line)
    else:
        with open(outfile, 'a') as f:
            f.write(line)

    # --- Plot fits ---
    fig, axs = plt.subplots(1, 2, figsize=(12, 5))

    axs[0].scatter(x1, y1, color='blue', label='Data', s=15)
    axs[0].plot(x1, gauss_linear(x1, *popt1), 'r-', lw=2, label='Fit')
    axs[0].set_title(f"Peak 1 Fit ({voltage} V)")
    axs[0].set_xlabel("Channel Number")
    axs[0].set_ylabel("Counts")
    axs[0].legend()

    axs[1].scatter(x2, y2, color='green', label='Data', s=15)
    axs[1].plot(x2, gauss_linear(x2, *popt2), 'r-', lw=2, label='Fit')
    axs[1].set_title(f"Peak 2 Fit ({voltage} V)")
    axs[1].set_xlabel("Channel Number")
    axs[1].set_ylabel("Counts")
    axs[1].legend()

    plt.tight_layout()
    plt.show()


# --- Batch processing of all files ---
def process_all_files(folder='.'):
    files = sorted([f for f in os.listdir(folder) if f.startswith("Co") and f.endswith("Peaks.txt")])
    if not files:
        print("No peak files found in directory.")
        return

    for file in files:
        match = re.search(r'(\d+)V', file)
        if not match:
            print(f"Skipping {file}: cannot extract voltage.")
            continue
        voltage = int(match.group(1))
        analyze_resolution(file, voltage)

    print("\n✅ Resolution analysis complete. Results saved to Resolution_Data.txt")


# --- Run the analysis ---
process_all_files()
