import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


if __name__ == "__main__":
    A = np.loadtxt("../output/state.txt")
    print(A.shape)
    t = np.loadtxt("../output/time.txt")
    fig = plt.figure(figsize=(12,12))
    ax = fig.add_subplot(111, projection='3d')
    ax.scatter(A[0,:], A[1,:], A[2,:], c=t, cmap="viridis", s = 1)

    # Labels
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    # Show plot
    plt.savefig("../plots/lorenz.png", dpi=1200)

    
