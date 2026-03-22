import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import os
import re

# --- Define Gaussian + linear background ---
def gauss_linear(x, A, mu, sigma, m, c):
    return A * np.exp(-((x - mu)**2) / (2 * sigma**2)) + m*x + c

# --- Function to compute Gaussian area ---
def gaussian_area(A, sigma):
    return A * np.sqrt(2 * np.pi) * abs(sigma)

# --- Main analysis function ---
def analyze_photopeaks(filename, voltage):
    # Read file, splitting two data sections by empty line
    with open(filename, 'r') as f:
        content = f.read().strip()

    parts = [p for p in content.split('\n\n') if p.strip()]  # split at blank lines
    if len(parts) != 2:
        raise ValueError("File should contain exactly 2 data sections separated by an empty line.")

    # Convert each section to numpy arrays
    data1 = np.loadtxt(parts[0].splitlines())
    data2 = np.loadtxt(parts[1].splitlines())

    x1, y1 = data1[:, 0], data1[:, 1]
    x2, y2 = data2[:, 0], data2[:, 1]

    # --- Fit Peak 1 ---
    p0_1 = [max(y1), x1[np.argmax(y1)], 5, 0, min(y1)]  # [A, mu, sigma, m, c]
    popt1, _ = curve_fit(gauss_linear, x1, y1, p0=p0_1)
    A1, mu1, sigma1, m1, c1 = popt1

    # --- Fit Peak 2 ---
    p0_2 = [max(y2), x2[np.argmax(y2)], 5, 0, min(y2)]
    popt2, _ = curve_fit(gauss_linear, x2, y2, p0=p0_2)
    A2, mu2, sigma2, m2, c2 = popt2

    # --- Calculate areas ---
    area_peak1 = gaussian_area(A1, sigma1)
    area_peak2 = gaussian_area(A2, sigma2)

    # --- Print results ---
    print(f"PMT Voltage: {voltage} V")
    print(f"1st Peak → Area = {area_peak1:.2f}")
    print(f"2nd Peak → Area = {area_peak2:.2f}")
    print()

    # --- Save results to file ---
    outfile = "Photopeak_Efficiency.txt"
    header = "PMT_Voltage(V)\tArea_Peak1\tArea_Peak2\n"
    line = f"{voltage}\t{area_peak1:.4f}\t{area_peak2:.4f}\n"

    if not os.path.exists(outfile):
        with open(outfile, 'w') as f:
            f.write(header)
            f.write(line)
    else:
        with open(outfile, 'a') as f:
            f.write(line)

    # --- Plot fits ---
    fig, axs = plt.subplots(1, 2, figsize=(12, 5))

    # Peak 1
    axs[0].scatter(x1, y1, color='blue', label='Data', s=15)
    axs[0].plot(x1, gauss_linear(x1, *popt1), color='red', label='Fit', lw=2)
    axs[0].set_title(f"Peak 1 Fit (PMT {voltage} V)")
    axs[0].set_xlabel("Channel Number")
    axs[0].set_ylabel("Counts")
    axs[0].legend()

    # Peak 2
    axs[1].scatter(x2, y2, color='green', label='Data', s=15)
    axs[1].plot(x2, gauss_linear(x2, *popt2), color='red', label='Fit', lw=2)
    axs[1].set_title(f"Peak 2 Fit (PMT {voltage} V)")
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
        analyze_photopeaks(file, voltage)

    print("\n✅ Resolution analysis complete. Results saved to Resolution_Data.txt")


# --- Example usage ---
process_all_files()
