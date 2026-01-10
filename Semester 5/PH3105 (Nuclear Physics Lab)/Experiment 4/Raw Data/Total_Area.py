import numpy as np
import os
import re

def compute_total_area(filename):
    """Reads the spectrum file and computes total area under the curve."""
    try:
        # Read file, skipping header lines that contain non-numeric data
        data = np.loadtxt(filename, comments=['#', ';'], usecols=(0, 1), skiprows=1)
    except Exception as e:
        print(f"Skipping {filename}: {e}")
        return None

    # Channel and counts
    x, y = data[:, 0], data[:, 1]

    # Approximate total area by summing counts (assuming equal bin widths)
    total_area = np.trapz(y, x)
    return total_area


def process_all_spectra(folder='.'):
    """Processes all Co *.asc files and saves total areas."""
    files = sorted([f for f in os.listdir(folder) if f.startswith("Co") and f.endswith(".asc")])

    if not files:
        print("No Co-60 spectrum files found in this directory.")
        return

    outfile = "Total_Area.txt"
    with open(outfile, 'w') as f:
        f.write("Voltage(V)\tArea\n")

        for file in files:
            # Extract voltage from filename using regex (e.g., 639 from "Co 639V.asc")
            match = re.search(r'(\d+)V', file)
            if not match:
                print(f"Could not extract voltage from {file}, skipping.")
                continue
            voltage = int(match.group(1))

            area = compute_total_area(file)
            if area is not None:
                print(f"{file}: Area = {area:.4f}")
                f.write(f"{voltage}\t{area:.6f}\n")

    print(f"\n✅ Results saved to {outfile}")


# --- Run the processing ---
process_all_spectra()
