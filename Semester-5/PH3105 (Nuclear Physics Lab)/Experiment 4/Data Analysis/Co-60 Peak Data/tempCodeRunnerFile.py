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