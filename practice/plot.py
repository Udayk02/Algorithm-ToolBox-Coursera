import matplotlib.pyplot as plt
import numpy as np
from numpy.lib.scimath import logn
n = np.linspace(-1, 1)
plt.plot(n, 3**n, label = "3^n")
plt.show()