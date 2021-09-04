import matplotlib.pyplot as plt
import numpy as np
from numpy.lib.scimath import logn
n = np.linspace(1, 300)
# plt.plot(n, 3 ** n, label="3^n")
# plt.plot(n, n * logn(2, n), label="nlog(2)n")
# plt.plot(n, logn(4, n), label="log(4)n")
# plt.plot(n, n, label="n")
# plt.plot(n, 5 ** logn(2, n), label="5^log(2)n")
# plt.plot(n, n ** 2, label="n^2")
# plt.plot(n, n ** .5, label="n^(1/2)")
# plt.plot(n, 4 ** n, label="2^(2n)")
# plt.legend(loc='upper left')
# plt.show()

# plt.plot(n, n ** (1/2), label="n^(1/2)")
# plt.plot(n, logn(10, n), label="log(n)")
# plt.legend(loc='upper left')
# plt.show()

# plt.plot(n, 10 ** n, label="10^n")
plt.plot(n, np.log(n) ** 3, label="(logn)^3")
plt.plot(n, n ** 0.5, label="n^0.5")
plt.legend(loc='upper left')
plt.show()